#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include "libs/leds.h"
#include "libs/buzzer.h"

// Função: Animação de um sorriso
void draw_smile(PIO pio, uint sm, float intensity);
// Função: Animação de uma contagem reegrissiva.
void draw_numbers(PIO pio, uint sm, float intensity);
void reset_leds(PIO pio, uint sm);
void logo_embarcatech(PIO pio, uint sm, float intensity);
void pacman(PIO pio, uint sm, float intensity);

#endif