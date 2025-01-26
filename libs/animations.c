#include "animations.h"

// CORES PARA AS ANIMAÇÕES

const pixel black = {0, 0, 0};
const pixel white = {213, 210, 210};
const pixel green = {32, 216, 26};
const pixel dark_green = {6, 80, 36};
const pixel brown = {181, 68, 81};
const pixel red = {252, 6, 6};
const pixel orange = {255, 65, 0};

void reset_leds(PIO pio, uint sm)
{

    frame frame, black_frame;
    // pinta todos os leds de preto
    for (uint i = 0; i < PIXELS; i++)
    {
        black_frame[i] = black;
        frame[i] = black;
    }

    // animação de reset
    for (uint i = 0; i < PIXELS; i++)
    {
        frame[i] = red;
        draw_pio(frame, pio, sm, 1);
        sleep_ms(50);
    }

    draw_pio(black_frame, pio, sm, 1);
    // aviso sonoro que terminou de resetar;
    sleep_ms(50);
    play_tone(BUZZER_A, 1000, 100);
    sleep_ms(50);
    play_tone(BUZZER_A, 2000, 100);

    stop_animation = false;
    is_animation_running = false;
}

void draw_smile(PIO pio, uint sm, float intensity)
{
    frame frames[5] = {
        {
            // linha 1
            dark_green,
            dark_green,
            dark_green,
            dark_green,
            dark_green,
            //     // linha 2
            dark_green,
            black,
            black,
            black,
            dark_green,
            //     // linha 3
            black,
            black,
            black,
            black,
            black,
            //     // linha 4
            black,
            dark_green,
            black,
            dark_green,
            black,
            //     // linha 5
            black,
            dark_green,
            black,
            dark_green,
            black,
        },
        {
            // linha 1
            dark_green,
            dark_green,
            dark_green,
            dark_green,
            dark_green,
            //     // linha 2
            dark_green,
            black,
            black,
            black,
            dark_green,
            //     // linha 3
            black,
            black,
            black,
            black,
            black,
            //     // linha 4
            black,
            dark_green,
            black,
            black,
            black,
            //     // linha 5
            black,
            black,
            black,
            dark_green,
            black,
        },
        {
            // linha 1
            black,
            dark_green,
            dark_green,
            dark_green,
            black,
            //     // linha 2
            dark_green,
            dark_green,
            dark_green,
            dark_green,
            dark_green,
            //     // linha 3
            black,
            black,
            black,
            black,
            black,
            //     // linha 4
            black,
            dark_green,
            black,
            dark_green,
            black,
            //     // linha 5
            black,
            dark_green,
            black,
            dark_green,
            black,
        },
        {
            // linha 1
            black,
            black,
            black,
            black,
            black,
            //     // linha 2
            black,
            dark_green,
            dark_green,
            dark_green,
            black,
            //     // linha 3
            black,
            black,
            black,
            black,
            black,
            //     // linha 4
            black,
            dark_green,
            black,
            dark_green,
            black,
            //     // linha 5
            black,
            dark_green,
            black,
            dark_green,
            black,
        },
        {
            // linha 1
            black,
            black,
            red,
            black,
            black,
            //     // linha 2
            black,
            dark_green,
            red,
            dark_green,
            black,
            //     // linha 3
            black,
            black,
            black,
            black,
            black,
            //     // linha 4
            black,
            dark_green,
            black,
            dark_green,
            black,
            //     // linha 5
            black,
            dark_green,
            black,
            dark_green,
            black,
        },
    };
    for (uint i = 0; i < 5; i++)
    {
        if (stop_animation)
        {
            printf("[INFO] Animação interrompida!\n");
            break;
        }
        draw_pio(frames[i], pio, sm, intensity);
        if (i != 4)
        {
            play_tone(BUZZER_A, 440, 250);
        }
        else
        {

            play_tone(BUZZER_A, 100, 100);
            sleep_ms(100);
            play_tone(BUZZER_A, 50, 100);
        }
        sleep_ms(500);
    }
}

// Função que gera a animação de contagem regressiva
void draw_numbers(PIO pio, uint sm, float intensity)
{
    // É utilizado a cor laranja em cada frame.
    frame frames[5] = {
        {black, orange, orange, orange, black,
         black, orange, black, black, black,
         black, orange, orange, orange, black,
         black, black, black, orange, black,
         black, orange, orange, orange, black},
        {black, orange, black, orange, black,
         black, orange, black, orange, black,
         black, orange, orange, orange, black,
         black, black, black, orange, black,
         black, black, black, orange, black},
        {black, orange, orange, orange, black,
         black, black, black, orange, black,
         black, black, orange, orange, black,
         black, black, black, orange, black,
         black, orange, orange, orange, black},
        {black, orange, orange, orange, black,
         black, black, black, orange, black,
         black, orange, orange, orange, black,
         black, orange, black, black, black,
         black, orange, orange, orange, black},
        {black, orange, orange, black, black,
         black, black, orange, black, black,
         black, black, orange, black, black,
         black, black, orange, black, black,
         black, orange, orange, orange, black}};
    for (uint i = 0; i < 5; i++)
    {
        if (stop_animation)
        {
            printf("[INFO] Animação interrompida!\n");
            break;
        }
        draw_pio(frames[i], pio, sm, intensity);
        if ((i % 2) == 0)
        {
            play_tone(BUZZER_A, 1000, 200);
            sleep_ms(100);
            play_tone(BUZZER_B, 1500, 100);
        }
        if ((i % 2) != 0)
        {
            play_tone(BUZZER_A, 1000, 200);
            sleep_ms(100);
            play_tone(BUZZER_B, 1500, 100);
        }
        sleep_ms(800);
    }
    sleep_ms(1000);
}