#include "print.h"

void kernel_main() {
  print_clear();
  print_set_color(PRINT_COLOR_BLACK, PRINT_COLOR_WHITE);
  print_str("# Welcome to Project NyxieOS Beta!");
  
}

void print(char* str);

int main() {
    print("Bem-vindo ao meu Sistema Operacional!");
    return 0;
}

void print(char* str) {
    while (*str) {
        __asm__ (
            "movb %0, %%al\n"
            "out %%al, $0x03f8"
            :
            : "r" (*str)
        );
        str++;
    }
}
