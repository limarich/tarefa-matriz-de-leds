#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include "libs/leds.h"
#include "libs/buzzer.h"

extern volatile bool stop_animation;
extern volatile bool is_animation_running;
// Função para desenhar um sorriso
void draw_smile(PIO pio, uint sm, float intensity);
void draw_numbers(PIO pio, uint sm, float intensity);
void reset_leds(PIO pio, uint sm);

#endif