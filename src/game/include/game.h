#pragma once
#include <cstdint>
#include <vector>
#include <thread>
#include <atomic>
#include <mutex>
#include <game/include/math.h>
#include <game/include/offsets.h>

struct game_camera {
    uemath::f_rotator rotation{};
    uemath::f_vector location{};
    float fov{ 80.0f };
};

struct game_entity {
    uintptr_t player_state{ 0 };
    uintptr_t pawn{ 0 };
    uintptr_t mesh{ 0 };
};

class c_game {
private:
    std::atomic<bool> m_running{ false };
    std::unique_ptr<std::thread> m_update_thread{ nullptr };

    game_camera m_camera{};
    std::vector<game_entity> m_entities{};

    uintptr_t m_gworld{ 0 };
    uintptr_t m_game_instance{ 0 };
    uintptr_t m_game_state{ 0 };
    uintptr_t m_local_player{ 0 };
    uintptr_t m_acknowledged_pawn{ 0 };
    uintptr_t m_camera_manager{ 0 };
public:
    uintptr_t m_player_controller{ 0 };

    void run_update();

    const game_camera& get_camera() const { return m_camera; }
    const std::vector<game_entity>& get_entities() const { return m_entities; }

    bool query_camera();
    bool collect_entities();

    bool is_visible(uintptr_t mesh);
    bool is_dead(uintptr_t pawn);

    uemath::f_vector get_bone_position(uintptr_t mesh, int id);
    uemath::f_vector2d world_to_screen(const uemath::f_vector& world) const;
};

inline c_game game;