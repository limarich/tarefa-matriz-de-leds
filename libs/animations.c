#include "animations.h"
#include "keyboard.h"
// CORES PARA AS ANIMAÇÕES

const pixel black = {0, 0, 0};
const pixel white = {213, 210, 210};
const pixel green = {32, 216, 26};
const pixel dark_green = {6, 80, 36};
const pixel brown = {181, 68, 81};
const pixel red = {252, 6, 6};
const pixel yellow = {241, 255, 0};
const pixel blue = {0, 143, 255};

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

void pacman(PIO pio, uint sm, float intensity){
    frame frames[10] = {
            {//linha 5
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            //linha 4
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            //linha 3
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            //linha 2
            yellow,
            blue,
            yellow,
            yellow,
            yellow,
            //linha 1
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
        },
        {
            //linha 5
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            //linha 4
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            //linha 3
            black,
            yellow,
            yellow,
            yellow,
            yellow,
            //linha 2
            yellow,
            blue,
            yellow,
            yellow,
            yellow,
            //linha 1
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
        },
        {
            //linha 5
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            //linha 4
            yellow,
            yellow,
            yellow,
            yellow,
            black,
            //linha 3
            black,
            black,
            yellow,
            yellow,
            yellow,
            //linha 2
            yellow,
            blue,
            yellow,
            yellow,
            black,
            //linha 1
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
        },
        {
            //linha 5
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            //linha 4
            yellow,
            yellow,
            yellow,
            black,
            black,
            //linha 3
            black,
            black,
            black,
            yellow,
            yellow,
            //linha 2
            yellow,
            blue,
            yellow,
            black,
            black,
            //linha 1
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
        },
        {
            //linha 5
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            //linha 4
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            //linha 3
            black,
            yellow,
            yellow,
            yellow,
            yellow,
            //linha 2
            yellow,
            blue,
            yellow,
            yellow,
            yellow,
            //linha 1
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
        },
        {
            //linha 5
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            //linha 4
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            //linha 3
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            //linha 2
            yellow,
            blue,
            yellow,
            yellow,
            yellow,
            //linha 1
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
        },
        {
            //linha 5
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            //linha 4
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            //linha 3
            black,
            yellow,
            yellow,
            yellow,
            yellow,
            //linha 2
            yellow,
            blue,
            yellow,
            yellow,
            yellow,
            //linha 1
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
        },
        {
            //linha 5
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            //linha 4
            yellow,
            yellow,
            yellow,
            yellow,
            black,
            //linha 3
            black,
            black,
            yellow,
            yellow,
            yellow,
            //linha 2
            yellow,
            blue,
            yellow,
            yellow,
            black,
            //linha 1
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
        },
        {
            //linha 5
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            //linha 4
            yellow,
            yellow,
            yellow,
            black,
            black,
            //linha 3
            black,
            black,
            black,
            yellow,
            yellow,
            //linha 2
            yellow,
            blue,
            yellow,
            black,
            black,
            //linha 1
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
        },
        {
            //linha 5
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            //linha 4
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            //linha 3
            black,
            yellow,
            yellow,
            yellow,
            yellow,
            //linha 2
            yellow,
            blue,
            yellow,
            yellow,
            yellow,
            //linha 1
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
        },
    };
    for (uint i = 0; i < 10; i++)
    {
        draw_pio(frames[i], pio, sm, intensity);
        if (i != 5)
        {
            play_tone(BUZZER_A, 415, 70);
        }
        else
        {
            play_tone(BUZZER_A, 466, 70);
            sleep_ms(50);
            play_tone(BUZZER_A, 50, 70);
        }
        sleep_ms(10);
    }
}