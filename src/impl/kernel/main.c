#include "print.h"

void kernel_main() {
  print_clear();
                  //Text Color        //Background Color
  print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
  print_str(" +-------------------------------------------------------------+\n");
  print_str(" |                                                             |\n");
	print_str(" |             [NyxieworldOS Version 0.0.2 <Allana>]           |\n");
	print_str(" |                2024-2025 Nyxieworld Project                 |\n");
	print_str(" |             (C) Copyright Nyxieworld Productions            |\n");
	print_str(" |                                                             |\n");
	print_str(" +-------------------------------------------------------------+\n");
  print_str(" [                  Development Release 0.0.2                  ]\n");
}
