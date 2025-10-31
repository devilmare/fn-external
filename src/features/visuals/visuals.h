#pragma once
#include <imgui/imgui.h>
#include <shared/globals.h>
#include <game/include/game.h>
#include <game/include/math.h>
#include <string>
#include <vector>

class c_visuals {
public:
    void render();
private:
    void draw_player_box(ImDrawList* draw_list, const uemath::f_vector2d& head2d, const uemath::f_vector2d& root2d);
    void draw_skeleton(ImDrawList* draw_list, uintptr_t mesh);
    void draw_snapline(ImDrawList* draw_list, const uemath::f_vector2d& root2d);
};

inline c_visuals visuals;
