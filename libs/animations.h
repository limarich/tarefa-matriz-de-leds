#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include "libs/leds.h"
#include "libs/buzzer.h"

// Função: Animação de um sorriso
void draw_smile(PIO pio, uint sm, float intensity);
// Função: Animação de uma contagem reegrissiva.
void draw_numbers(PIO pio, uint sm, float intensity);
// Função: Animação da logo da Embratech
void logo_embratech(PIO pio, uint sm, float intensity);
// Função: Animação do Pacman
void pacman(PIO pio, uint sm, float intensity);
#endif