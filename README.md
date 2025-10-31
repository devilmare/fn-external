## fn-external (Fortnite External Cheat)

A very simple external cheat with an overlay using ImGui and DirectX 11.

### Features
- Basic overlay and visuals
- ImGui-based UI (DX11 + Win32 backends)
- Game SDK with latest offsets
- Player visual (box, bone, snapline)

### Requirements
- Windows 10/11
- Visual Studio 2022 (v143 toolset)
- DirectX 11 runtime (included with Windows)

### Build
1. Open `fn-external.sln` in Visual Studio.
2. Select `Release | x64`.
3. Build the solution.

### Run
- Launch Fortnite first, then run the built executable from `bin/`.

### Notes
- Uses third-party ImGui files in `thirdparty/imgui/`.
- Source is organized under `src/` (game, overlay, features, driver).

### Disclaimer
- This project is just a base. You are responsible for how you use it
- You also need your own driver

### Communication

Discord: @qgqs