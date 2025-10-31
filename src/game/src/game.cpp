#include "../include/game.h"

#include <driver/driver.h>
#include <shared/globals.h>

#include <protection/string_obfuscation.h>

void c_game::run_update()
{
    if (!driver.m_base_address)
    {
        return;
    }

    while (true)
    {
        if (!m_gworld)
        { 
            m_gworld = driver.read<uintptr_t>(driver.m_base_address + Offsets::Globals::UWorld);
            if (!driver.is_valid(m_gworld))
            {
                printf(e("Failed to get m_gworld class\n"));
                continue;
            }
        }

        if (!m_game_instance)
        {
            m_game_instance = driver.read<uintptr_t>(m_gworld + Offsets::UWorld::OwningGameInstance);
            if (!driver.is_valid(m_game_instance))
            {
                printf(e("Failed to get m_game_instance class\n"));
                continue;
            }
        }

        if (!m_game_state)
        {
            m_game_state = driver.read<uintptr_t>(m_gworld + Offsets::UWorld::GameState);
            if (!driver.is_valid(m_game_state))
            {
                printf(e("Failed to get m_game_state class\n"));
                continue;
            }
        }

        if (!m_local_player)
        {
            auto local_players = driver.read<uemath::tarray<uintptr_t>>(m_game_instance + Offsets::UGameInstance::LocalPlayers);
            if (local_players.count > 0 && local_players.data) { m_local_player = local_players.get(0); }
            if (!driver.is_valid(m_local_player))
            {
                printf(e("Failed to get m_local_player class\n"));
                continue;
            }
        }

        if (!m_player_controller)
        {
            m_player_controller = driver.read<uintptr_t>(m_local_player + Offsets::UPlayer::PlayerController);
            if (!driver.is_valid(m_player_controller))
            {
                printf(e("Failed to get m_player_controller class\n"));
                continue;
            }
        }

        if (!m_acknowledged_pawn)
        {
            m_acknowledged_pawn = driver.read<uintptr_t>(m_player_controller + Offsets::APlayerController::AcknowledgedPawn);
        }

        if (m_gworld && m_player_controller)
        {
            query_camera();
            collect_entities();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

bool c_game::query_camera()
{
    if (!m_gworld || !m_player_controller)
    {
        return false;
    }

    auto location_callback = driver.read<uintptr_t>(m_gworld + Offsets::Globals::CameraLocation);
    auto rotation_callback = driver.read<uintptr_t>(m_gworld + Offsets::Globals::CameraRotation);

    if (!location_callback || !rotation_callback)
    {
        return false;
    }

    struct rot_struct
    {
        double pitch;
        char pad_0008[24];
        double yaw;
        char pad_0028[424];
        double roll;
    } rot;

    rot.pitch = driver.read<double>(rotation_callback);
    rot.yaw = driver.read<double>(rotation_callback + 0x20);
    rot.roll = driver.read<double>(rotation_callback + 0x1d0);

    m_camera.location = driver.read<uemath::f_vector>(location_callback);
    m_camera.rotation.pitch = asin(rot.roll) * (180.0 / M_PI);
    m_camera.rotation.yaw = ((atan2(rot.pitch * -1, rot.yaw) * (180.0 / M_PI)) * -1) * -1;
    m_camera.rotation.roll = rot.roll;
    m_camera.fov = driver.read<float>(m_player_controller + Offsets::APlayerController::PlayerCameraFov) * 90.f;

    return true;
}

bool c_game::collect_entities()
{
    m_entities.clear();

    if (!m_gworld || !m_game_state)
        return false;

    auto player_array = driver.read<uemath::tarray<uintptr_t>>(m_game_state + Offsets::AGameStateBase::PlayerArray);
    if (!player_array.data || player_array.count == 0)
    {
        return true;
    }

    const uint32_t max_players = (std::min)(player_array.count, 200u);
    for (uint32_t i = 0; i < max_players; ++i)
    {
        auto state = player_array.get(i);
        if (!driver.is_valid(state))
        {
            continue;
        }

        auto pawn = driver.read<uintptr_t>(state + Offsets::APlayerState::PawnPrivate);
        if (!driver.is_valid(pawn))
        {
            continue;
        }

        if (pawn == m_acknowledged_pawn)
        {
            continue;
        }

        auto mesh = driver.read<uintptr_t>(pawn + Offsets::ACharacter::Mesh);
        if (!driver.is_valid(mesh))
        {
            continue;
        }

        m_entities.push_back({ state, pawn, mesh });
    }
    
    return true;
}

uemath::f_vector2d c_game::world_to_screen(const uemath::f_vector& world) const
{
    D3DMATRIX temp_matrix = uemath::rotation_matrix(m_camera.rotation);
    
    auto v_axis_x = uemath::f_vector(temp_matrix.m[0][0], temp_matrix.m[0][1], temp_matrix.m[0][2]);
    auto v_axis_y = uemath::f_vector(temp_matrix.m[1][0], temp_matrix.m[1][1], temp_matrix.m[1][2]);
    auto v_axis_z = uemath::f_vector(temp_matrix.m[2][0], temp_matrix.m[2][1], temp_matrix.m[2][2]);

    uemath::f_vector v_delta = world - m_camera.location;
    uemath::f_vector v_transformed = uemath::f_vector(v_delta.dot(v_axis_y), v_delta.dot(v_axis_z), v_delta.dot(v_axis_x));

    if (v_transformed.z < 1.0f)
        v_transformed.z = 1.0f;

    float screen_center_x = globals.gui.screen_size.x / 2;
    float screen_center_y = globals.gui.screen_size.y / 2;
    
    float fov_rad = m_camera.fov * float(std::numbers::pi) / 360.0f;
    float fov_tan = tanf(fov_rad);
    
    float screen_x = screen_center_x + v_transformed.x * (screen_center_x / fov_tan) / v_transformed.z;
    float screen_y = screen_center_y - v_transformed.y * (screen_center_x / fov_tan) / v_transformed.z;

    return uemath::f_vector2d(screen_x, screen_y);
}

uemath::f_vector c_game::get_bone_position(uintptr_t mesh, int id)
{
    if (!mesh)
        return uemath::f_vector();

    uintptr_t bone_array = driver.read<uintptr_t>(mesh + 0x5E8);
    if (bone_array == NULL)
    {
        bone_array = driver.read<uintptr_t>(mesh + 0x5E8 + 0x10);
    }

    if (!bone_array)
        return uemath::f_vector();

    auto BoneTransform = driver.read<d3dmatrix::FTransform>(bone_array + (id * 0x60));
    d3dmatrix::FTransform ComponentToWorld2 = driver.read<d3dmatrix::FTransform>(mesh + 0x1e0);
    D3DMATRIX Matrix = d3dmatrix::MatrixMultiplication(BoneTransform.ToMatrixWithScale(), ComponentToWorld2.ToMatrixWithScale());
    return uemath::f_vector(Matrix._41, Matrix._42, Matrix._43);
}

bool c_game::is_visible(uintptr_t mesh)
{
    if (!mesh)
        return false;

    auto seconds = driver.read<double>(m_gworld + Offsets::Globals::CameraRotation + 0x10);
    auto last_render_time = driver.read<float>(mesh + 0x32C);
    return seconds - last_render_time <= 0.06f;
}

bool c_game::is_dead(uintptr_t pawn)
{
    return (driver.read<char>(pawn + Offsets::AFortPawn::bIsDying) >> 5) & 1;
}
