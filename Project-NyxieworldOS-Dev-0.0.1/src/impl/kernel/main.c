#include "print.h"

void kernel_main() {
  print_clear();
  print_set_color(PRINT_COLOR_BLACK, PRINT_COLOR_WHITE);
  print_str("# Bem-vindo, ao Nyxieworld OS com suporte 64bit! \n");
  print_str("# Copyright© 2024-2025 Nyxieworld Project \n");
  print_str("# Nyxieworld OS [Melissa] v0.0.1 \n");
}
