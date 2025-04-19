#include "print.h"

void kernel_main() {
  print_clear();
  print_set_color(PRINT_COLOR_BLACK, PRINT_COLOR_WHITE);
  print_str("# Bem-vindo, ao Nyxieworld OS com suporte 64bit! \n");
  print_str("# (C) Copyright 2024-2025 Nyxieworld Project \n");
  print_str(" \n");
  print_str(" +--------------------------------------------+\n");
	print_str(" |   [NyxieworldOS Version 0.0.1 <Melissa>]   |\n");
	print_str(" +--------------------------------------------+\n");
	print_str(" |        2024-2025 Nyxieworld Project        |\n");
	print_str(" +--------------------------------------------+\n");
	print_str(" |-----------PRESS [ENTER] TO REBOOT----------|\n");
	print_str(" +--------------------------------------------+\n");

}
