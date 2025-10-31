#include "overlay.h"

#include <shared/globals.h>

#include <features/visuals/visuals.h>
#include <protection/string_obfuscation.h>

bool c_overlay::setup_overlay()
{
    m_window_handle = FindWindowA(e("AMDDVROVERLAYWINDOWCLASS"), e("amd dvr overlay"));
    if (!m_window_handle)
        return false;

    DwmExtendFrameIntoClientArea(m_window_handle, &m_margin);
    SetLayeredWindowAttributes(m_window_handle, RGB(0, 0, 0), 255, LWA_ALPHA);

    ShowWindow(m_window_handle, SW_SHOW);
    UpdateWindow(m_window_handle);

    DXGI_SWAP_CHAIN_DESC scd;
    ZeroMemory(&scd, sizeof(scd));
    scd.BufferCount = 2;
    scd.BufferDesc.Width = 0;
    scd.BufferDesc.Height = 0;
    scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    scd.BufferDesc.RefreshRate.Numerator = 60;
    scd.BufferDesc.RefreshRate.Denominator = 1;
    scd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
    scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    scd.OutputWindow = m_window_handle;
    scd.SampleDesc.Count = 1;
    scd.SampleDesc.Quality = 0;
    scd.Windowed = TRUE;
    scd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    UINT flags = 0;
    D3D_FEATURE_LEVEL used_level;
    D3D_FEATURE_LEVEL levels[] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0 };

    if (FAILED(D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, flags, levels, 2, D3D11_SDK_VERSION, &scd, &m_swap_chain, &m_device, &used_level, &m_device_context)))
        return false;

    ID3D11Texture2D* back_buffer = nullptr;
    m_swap_chain->GetBuffer(0, IID_PPV_ARGS(&back_buffer));
    if (back_buffer == nullptr)
        return false;

    m_device->CreateRenderTargetView(back_buffer, NULL, &m_render_target_view);
    back_buffer->Release();

    // add ur own overlay & screen size

	globals.gui.screen_size = ImVec2(1920, 1080);

    return true;
}

bool c_overlay::setup_imgui()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
    io.IniFilename = nullptr;
    io.LogFilename = nullptr;

    ImGui_ImplWin32_Init(m_window_handle);
    ImGui_ImplDX11_Init(m_device, m_device_context);

    bool m_running = true;

    MSG msg;
    while (m_running)
    {
        while (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
            {
                m_running = false;
                break;
            }
        }

        if (!m_running) break;

        if (GetAsyncKeyState(VK_INSERT) & 1)
        {
            m_visible = !m_visible;
        }

        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        {
            render();
            visuals.render();
        }

        ImGui::Render();

        const float clear_color[4] = { 0, 0, 0, 0 };
        m_device_context->OMSetRenderTargets(1, &m_render_target_view, nullptr);
        m_device_context->ClearRenderTargetView(m_render_target_view, clear_color);

        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
        m_swap_chain->Present(0, 0);
    }

    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    if (m_render_target_view) { m_render_target_view->Release(); m_render_target_view = nullptr; }
    if (m_swap_chain) { m_swap_chain->Release(); m_swap_chain = nullptr; }
    if (m_device_context) { m_device_context->Release(); m_device_context = nullptr; }
    if (m_device) { m_device->Release(); m_device = nullptr; }
    if (m_window_handle) { DestroyWindow(m_window_handle); m_window_handle = nullptr; }

    return true;
}

void c_overlay::render()
{
    if (!m_visible)
        return;

    ImGui::SetNextWindowSize(globals.gui.window_size);
    ImGui::SetNextWindowPos(globals.gui.screen_size / 2 - globals.gui.window_size / 2, ImGuiCond_Once);
    ImGui::Begin(e("Nexus Toolkit"), nullptr);
    {
        if (ImGui::BeginTabBar(e("MainTabs"), ImGuiTabBarFlags_None))
        {
            if (ImGui::BeginTabItem(e("Visual")))
            {
				ImGui::Checkbox(e("Enable Visuals"), &globals.visual.enable);
				ImGui::Checkbox(e("Box"), &globals.visual.box);
				ImGui::Checkbox(e("Skeleton"), &globals.visual.skeleton);
				ImGui::Checkbox(e("Snapline"), &globals.visual.snapline);

                ImGui::Separator();

				ImGui::SliderFloat(e("Max Distance"), &globals.visual.max_distance, 50.f, 1000.f);
				ImGui::Combo(e("Box Mode"), &globals.visual.box_mode, e("Full Box\0Corner Box\0"));
                ImGui::Separator();

				ImGui::ColorEdit4(e("Box Color"), globals.visual.box_color);
				ImGui::ColorEdit4(e("Bone Color"), globals.visual.bone_color);
				ImGui::ColorEdit4(e("Snaplines Color"), globals.visual.snaplines_color);

                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }
    }
    ImGui::End();
}

bool c_overlay::setup()
{
    if (!setup_overlay())
    {
        printf(e("[!] Failed to create overlay context\n"));
        return false;
    }

    if (!setup_imgui())
    {
        printf(e("[!] Failed to setup ImGui\n"));
        return false;
    }

    return true;
}