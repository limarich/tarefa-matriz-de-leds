#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include "libs/leds.h"
#include "libs/buzzer.h"

// Função para desenhar um sorriso
void draw_smile(PIO pio, uint sm, float intensity);

// Função que gera a animação de contagem regressiva
void draw_numbers(PIO pio, uint sm, float intensity);

// Função para desenhar o logo da Embratech
void logo_embratech(PIO pio, uint sm, float intensity);




#endif