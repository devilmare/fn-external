#pragma once
#include <windows.h>
#include <dwmapi.h>
#include <dxgi.h>
#include <d3d11.h>
#include <functional>
#include <iostream>
#include <thread>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_win32.h>
#include <imgui/imgui_impl_dx11.h>

class c_overlay {
private:
    bool m_visible{ false };
    bool dpi_changed{ false };

    HWND m_window_handle = nullptr;
    ID3D11Device* m_device = nullptr;
    ID3D11DeviceContext* m_device_context = nullptr;
    ID3D11RenderTargetView* m_render_target_view = nullptr;
    IDXGISwapChain* m_swap_chain = nullptr;
    MARGINS m_margin = { -1 };

    bool setup_overlay();
    bool setup_imgui();
    void render();
public:
    bool setup();
    bool is_menu_open() const { return m_visible; }
    void set_menu_open(bool open) { m_visible = open; }
};

inline c_overlay overlay;