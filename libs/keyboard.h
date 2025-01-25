#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdio.h>
#include <stdbool.h>
#include "hardware/gpio.h"

// Definições de pinos e mapeamento do teclado
#define ROWS 4
#define COLS 4
extern const uint ROW_PINS[ROWS];
extern const uint COL_PINS[COLS];
extern const char KEYPAD[ROWS][COLS];

// Inicializa os pinos do teclado
void setup_keyboard(void);

// Lê o teclado matricial e retorna o caractere pressionado ou '\0' se nada for pressionado
char scan_keypad(void);

// Converte a tecla pressionada em uma string de código Morse
const char *get_morse_from_key(char key);

// Verifica se uma tecla específica foi pressionada
bool is_key_pressed(char key);

#endif // KEYBOARD_H
