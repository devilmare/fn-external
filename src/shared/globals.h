#pragma once
#include <vector>
#include <string>
#include <imgui/imgui.h>

class c_globals {
public:
	struct
	{
		ImVec2 window_size{ 0.0f, 0.0f };
		ImVec2 screen_size{ 0.0f, 0.0f };
	} gui;

	struct
	{
		bool enable{ false };

		bool box{ false };
		bool skeleton{ false };
		bool snapline{ false };

		float max_distance { 200.f };

		int box_mode{ 0 };

		float box_color[4]{ 1.0f, 1.0f, 1.0f, 1.0f };
		float bone_color[4]{ 1.0f, 1.0f, 1.0f, 1.0f };
		float snaplines_color[4]{ 1.0f, 1.0f, 0.0f, 1.0f };
	} visual;
};

inline c_globals globals;