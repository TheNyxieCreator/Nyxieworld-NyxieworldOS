#include "print.h"

// Definição da fonte 8x8
static const uint8_t font8x8_basic[128][8] = {
    // ... Definições de cada caractere
};

const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;

struct Char {
    uint8_t character;
    uint8_t color;
};

struct Char* buffer = (struct Char*) 0xb8000;
size_t col = 0;
size_t row = 0;
uint8_t color = PRINT_COLOR_WHITE | PRINT_COLOR_BLACK << 4;

void clear_row(size_t row) {
    struct Char empty = (struct Char) { ' ', color };
    for (size_t col = 0; col < NUM_COLS; col++) {
        buffer[col + NUM_COLS * row] = empty;
    }
}

void print_clear() {
    for (size_t i = 0; i < NUM_ROWS; i++) {
        clear_row(i);
    }
}

void print_newline() {
    col = 0;
    if (row < NUM_ROWS - 1) {
        row++;
        return;
    }
    for (size_t row = 1; row < NUM_ROWS; row++) {
        for (size_t col = 0; col < NUM_COLS; col++) {
            struct Char character = buffer[col + NUM_COLS * row];
            buffer[col + NUM_COLS * (row - 1)] = character;
        }
    }
    clear_row(NUM_COLS - 1);
}

void print_char(char character) {
    if (character == '\n') {
        print_newline();
        return;
    }
    if (col > NUM_COLS) {
        print_newline();
    }
    buffer[col + NUM_COLS * row] = (struct Char) { (uint8_t) character, color };
    col++;
}

void print_str(char* str) {
    for (size_t i = 0; 1; i++) {
        char character = (uint8_t) str[i];
        if (character == '\0') {
            return;
        }
        print_char(character);
    }
}

void print_set_color(uint8_t foreground, uint8_t background) {
    color = foreground + (background << 4);
}

// Funções Gráficas
void draw_pixel(int x, int y, uint8_t color) {
    // Função para desenhar um pixel na posição (x, y) com a cor (color)
    // Supondo que temos uma função de assembly para desenhar pixels
    putpixel(x, y, color);
}

void draw_char(int x, int y, char c, uint8_t color) {
    // Aqui você pode desenhar o caractere 'c' na posição (x, y) com a cor 'color'
    // Isso seria feito colocando pixels na posição correta, usando uma fonte bitmap
    // ou similar, dependendo de como você desenha gráficos no seu sistema
    // Esta função é simplificada
    // Supondo que cada caractere tem 8x8 pixels
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (font8x8_basic[c][i] & (1 << j)) {
                draw_pixel(x + j, y + i, color);
            }
        }
    }
}

void draw_string(int x, int y, char* str, uint8_t color) {
    for (size_t i = 0; str[i] != '\0'; i++) {
        draw_char(x + i * 8, y, str[i], color);  // Assumindo largura de caractere 8 pixels
    }
}

