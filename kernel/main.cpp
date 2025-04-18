#include "kernel.hpp"

extern "C" void kmain(void* multiboot_structure, unsigned int magicnumber){
	
	NyxieworldOS terminal;

	terminal.printf(" +------------------------------------------+\n");
	terminal.printf(" |  [NyxieworldOS Version 0.0.1 <Melissa>]  |\n");
	terminal.printf(" +------------------------------------------+\n");
	terminal.printf(" |       2024-2025 Nyxieworld Project       |\n");
	terminal.printf(" +------------------------------------------+\n");
	terminal.printf(" |----------PRESS [ENTER] TO REBOOT---------|\n");
	terminal.printf(" +------------------------------------------+\n");

	while (1){
		uint8_t scancode = terminal.read_key_scancode();
		if (scancode == terminal.ENTER_SCANCODE) {
			terminal.printf("\n[REBOOTING NOW...]\n");
			terminal.reboot_system(); //Reboot the system
		}

	}

}
