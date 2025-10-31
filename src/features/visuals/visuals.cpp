#include "visuals.h"
#include <overlay/overlay.h>
#include <game/include/game.h>
#include <driver/driver.h>
#include <game/include/offsets.h>
#include <game/include/math.h>
#include <algorithm>
#include <cmath>

void c_visuals::render()
{
    if (!globals.visual.enable)
        return;

    auto* draw_list = ImGui::GetBackgroundDrawList();
    if (!draw_list)
        return;

    const auto& cam = game.get_camera();
    const auto& entities = game.get_entities();

    for (const auto& ent : entities)
    {
        if (!ent.pawn || !ent.mesh)
            continue;

        auto head_pos = game.get_bone_position(ent.mesh, 114);
        auto root_pos = game.get_bone_position(ent.mesh, 0);

        const float distance = std::sqrt(std::pow(cam.location.x - root_pos.x, 2) + std::pow(cam.location.y - root_pos.y, 2) + std::pow(cam.location.z - root_pos.z, 2)) / 100.0f;
        if (distance > globals.visual.max_distance)
            continue;

        auto head2d = game.world_to_screen(head_pos);
        auto root2d = game.world_to_screen(root_pos);
        auto head_p = game.world_to_screen({ head_pos.x, head_pos.y, head_pos.z + 15 });

        if (!head2d.is_valid() || !root2d.is_valid() || !head2d.in_screen() || !root2d.in_screen())
            continue;

        if (globals.visual.box)
            draw_player_box(draw_list, head_p, root2d);

        if (globals.visual.skeleton)
            draw_skeleton(draw_list, ent.mesh);

        if (globals.visual.snapline)
            draw_snapline(draw_list, root2d);
    }
}

void c_visuals::draw_player_box(ImDrawList* draw_list, const uemath::f_vector2d& head2d, const uemath::f_vector2d& root2d)
{
    float height = std::abs(head2d.y - root2d.y) * 1.0f;
    float width = height * 0.5f;
    float x = head2d.x - width / 2.0f;
    float y = head2d.y;

    ImVec2 box_min(x, y);
    ImVec2 box_max(x + width, y + height);

    ImU32 color = IM_COL32((int)(globals.visual.box_color[0] * 255), (int)(globals.visual.box_color[1] * 255), (int)(globals.visual.box_color[2] * 255), (int)(globals.visual.box_color[3] * 255));

    if (globals.visual.box_mode == 0)
    {
        draw_list->AddRect(ImVec2(box_min.x - 1, box_min.y - 1), ImVec2(box_max.x + 1, box_max.y + 1), IM_COL32(0, 0, 0, 220), 0.0f, 0, 2.0f);
        draw_list->AddRect(box_min, box_max, color, 0.0f, 0, 1.5f);
    }
    else if (globals.visual.box_mode == 1)
    {
        float corner_size = min(width, height) * 0.2f;
        
        // Top-left corner
        draw_list->AddLine(ImVec2(x - 1, y - 1), ImVec2(x + corner_size - 1, y - 1), IM_COL32(0, 0, 0, 220), 3.0f);
        draw_list->AddLine(ImVec2(x - 1, y - 1), ImVec2(x - 1, y + corner_size - 1), IM_COL32(0, 0, 0, 220), 3.0f);
        draw_list->AddLine(ImVec2(x, y), ImVec2(x + corner_size, y), color, 2.0f);
        draw_list->AddLine(ImVec2(x, y), ImVec2(x, y + corner_size), color, 2.0f);
        
        // Top-right corner
        draw_list->AddLine(ImVec2(x + width + 1, y - 1), ImVec2(x + width - corner_size + 1, y - 1), IM_COL32(0, 0, 0, 220), 3.0f);
        draw_list->AddLine(ImVec2(x + width + 1, y - 1), ImVec2(x + width + 1, y + corner_size - 1), IM_COL32(0, 0, 0, 220), 3.0f);
        draw_list->AddLine(ImVec2(x + width, y), ImVec2(x + width - corner_size, y), color, 2.0f);
        draw_list->AddLine(ImVec2(x + width, y), ImVec2(x + width, y + corner_size), color, 2.0f);
        
        // Bottom-left corner
        draw_list->AddLine(ImVec2(x - 1, y + height + 1), ImVec2(x + corner_size - 1, y + height + 1), IM_COL32(0, 0, 0, 220), 3.0f);
        draw_list->AddLine(ImVec2(x - 1, y + height + 1), ImVec2(x - 1, y + height - corner_size + 1), IM_COL32(0, 0, 0, 220), 3.0f);
        draw_list->AddLine(ImVec2(x, y + height), ImVec2(x + corner_size, y + height), color, 2.0f);
        draw_list->AddLine(ImVec2(x, y + height), ImVec2(x, y + height - corner_size), color, 2.0f);
        
        // Bottom-right corner
        draw_list->AddLine(ImVec2(x + width + 1, y + height + 1), ImVec2(x + width - corner_size + 1, y + height + 1), IM_COL32(0, 0, 0, 220), 3.0f);
        draw_list->AddLine(ImVec2(x + width + 1, y + height + 1), ImVec2(x + width + 1, y + height - corner_size + 1), IM_COL32(0, 0, 0, 220), 3.0f);
        draw_list->AddLine(ImVec2(x + width, y + height), ImVec2(x + width - corner_size, y + height), color, 2.0f);
        draw_list->AddLine(ImVec2(x + width, y + height), ImVec2(x + width, y + height - corner_size), color, 2.0f);
    }
}

void c_visuals::draw_skeleton(ImDrawList* draw_list, uintptr_t mesh)
{
    ImU32 color = IM_COL32((int)(globals.visual.bone_color[0] * 255), (int)(globals.visual.bone_color[1] * 255), (int)(globals.visual.bone_color[2] * 255), (int)(globals.visual.bone_color[3] * 255));

    const std::vector<std::pair<int, int>> skeleton_bones = {
        {67, 9}, {9, 10}, {10, 11},           // Spine
        {67, 38}, {38, 39}, {39, 40},         // Left arm
        {67, 2}, {2, 71}, {71, 72}, {72, 75}, // Left leg
        {2, 78}, {78, 79}, {79, 82}           // Right leg
    };

    for (const auto& [bone_a, bone_b] : skeleton_bones)
    {
        auto pos_a = game.get_bone_position(mesh, bone_a);
        auto pos_b = game.get_bone_position(mesh, bone_b);
        
        auto screen_a = game.world_to_screen(pos_a);
        auto screen_b = game.world_to_screen(pos_b);
        
        if (screen_a.is_valid() && screen_b.is_valid() && screen_a.in_screen() && screen_b.in_screen())
        {
            draw_list->AddLine(ImVec2(screen_a.x, screen_a.y), ImVec2(screen_b.x, screen_b.y), color, 1.0f);
        }
    }
}

void c_visuals::draw_snapline(ImDrawList* draw_list, const uemath::f_vector2d& root2d)
{
    ImU32 color = IM_COL32((int)(globals.visual.snaplines_color[0] * 255), (int)(globals.visual.snaplines_color[1] * 255), (int)(globals.visual.snaplines_color[2] * 255), (int)(globals.visual.snaplines_color[3] * 255));

    ImVec2 start_pos(globals.gui.screen_size.x * 0.5f, globals.gui.screen_size.y);
    ImVec2 end_pos(root2d.x, root2d.y);
    
    draw_list->AddLine(start_pos, end_pos, color, 1.5f);
}