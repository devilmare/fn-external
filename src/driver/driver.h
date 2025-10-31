#pragma once

#include <Windows.h>
#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <cstdarg>
#include <TlHelp32.h>
#include <map>
#include <chrono>
#include <ntstatus.h>

#include <shared/definitions.h>

class c_driver {
private:
    HANDLE m_device_handle = INVALID_HANDLE_VALUE;
    ULONG m_target_process_id = 0;

    bool send_ioctl(ULONG ioctl_code, PVOID input_buffer, ULONG input_size, PVOID output_buffer, ULONG output_size, PULONG bytes_returned = nullptr);
    bool find_process_by_name(const wchar_t* process_name, ULONG* process_id);
    
public:
	uintptr_t m_base_address = 0;
    uintptr_t m_process_dtb = 0;

    bool setup();
    bool unload();

    bool attach(const wchar_t* target_name);

    bool read_memory(uintptr_t address, void* buffer, size_t size);
    bool write_memory(uintptr_t address, void* buffer, size_t size);

    bool mouse_move(LONG x, LONG y, USHORT button_flags = 0);

    std::uintptr_t get_base_address();
    std::uintptr_t get_process_dtb();
    std::uintptr_t get_module_base(const std::string& module_name);

    template<typename T>
    T read(uintptr_t address)
    {
        T value{};
        read_memory(address, &value, sizeof(T));
        return value;
    }

    template<typename T>
    bool write(uintptr_t address, const T& value)
    {
        return write_memory(address, (void*)&value, sizeof(T));
    }

    bool is_valid(uintptr_t pointer)
    {
        return (pointer && pointer > 0xFFFFFF && pointer < 0x7FFFFFFFFFFF && pointer != NULL);
    }

    std::string read_string(std::uintptr_t Address)
    {
        char buffer[128];
        read_memory(Address, (std::uint8_t*)&buffer, sizeof(buffer));
        return std::string(buffer, strlen(buffer));
    };

    std::wstring read_wstring(std::uintptr_t Address)
    {
        wchar_t buffer[128];
        read_memory(Address, (std::uint8_t*)&buffer, sizeof(buffer));
        return std::wstring(buffer, wcslen(buffer));
    }

    std::uintptr_t get_process_id() const { return m_target_process_id; }
};

inline c_driver driver;