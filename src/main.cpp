#include <Windows.h>
#include <iostream>
#include <thread>
#include <chrono>

#include <overlay/overlay.h>
#include <shared/globals.h>
#include <driver/driver.h>
#include <game/include/game.h>

#include <protection/string_obfuscation.h>

auto main() -> std::int32_t
{
	printf(e("[*] Starting...\n"));

	if (!driver.setup())
	{
		printf(e("[!] Failed to setup driver connection, Make sure the driver is loaded via mapper\n"));
		std::cin.get();
		return 1;
	}

	printf(e("[*] Driver connection established successfully.\n"));

	if (!driver.attach(L"FortniteClient-Win64-Shipping.exe"))
	{
		printf(e("[!] Failed to attach to target process, make sure it's running\n"));
		driver.unload();
		std::cin.get();
		return 1;
	}

	std::thread(&c_game::run_update, &game).detach();

	if (!overlay.setup())
	{
		printf(e("[!] Failed to setup overlay\n"));
		driver.unload();
		std::cin.get();
		return 1;
	}

	printf(e("[*] Overlay setup complete. Press any key to exit...\n"));
	std::cin.get();
	driver.unload();

	return 0;
}