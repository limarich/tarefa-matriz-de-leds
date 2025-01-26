#include "animations.h"

// CORES PARA AS ANIMAÇÕES

const pixel black = {0, 0, 0};
const pixel white = {213, 210, 210};
const pixel green = {32, 216, 26};
const pixel dark_green = {6, 80, 36};
const pixel brown = {181, 68, 81};
const pixel red = {252, 6, 6};
const pixel blue = {65, 105, 225};

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

void logo_embratech(PIO pio, uint sm, float intensity)
{
    frame frames[18] = {
        // 1° Frame - Parte 1
        {
            black, black, black, black, black, // linha 1 
            black, black, black, black, black, // linha 2
            black, black, black, black, black, // linha 3
            black, black, black, black, black, // linha 4
            black, black, black, black, black, // linha 5
        },

        // 2° Frame - Parte 2.1
        {
            blue, black, black, black, black,     // linha 1 
            black, black, black, black, black, // linha 2
            black, black, black, black, black, // linha 3
            black, black, black, black, black, // linha 4
            black, black, black, black, black, // linha 5
        },
        // 3° Frame - Parte 2.2
         {
            blue, blue, black, black, black,     // linha 1 
            black, black, black, black, black, // linha 2
            black, black, black, black, black, // linha 3
            black, black, black, black, black, // linha 4
            black, black, black, black, black, // linha 5
        },
        // 4° Frame - Parte 2.3
        {
            blue, blue, blue, black, black,     // linha 1 
            black, black, black, black, black, // linha 2
            black, black, black, black, black, // linha 3
            black, black, black, black, black, // linha 4
            black, black, black, black, black, // linha 5
        },
        // 5° Frame - Parte 2.4
        {
            blue, blue, blue, blue, black,     // linha 1 
            black, black, black, black, black, // linha 2
            black, black, black, black, black, // linha 3
            black, black, black, black, black, // linha 4
            black, black, black, black, black, // linha 5
        },

        // 6° Frame - Parte 3.1
        { 
            blue, blue, blue, blue, black,    // linha 1
            black, blue, black, black, black, // linha 2
            black, black, black, black, black, // linha 3
            black, black, black, black, black, // linha 4
            black, black, black, black, black, // linha 5

        },
        // 7° Frame - Parte 3.2
        { 
            blue, blue, blue, blue, black,    // linha 1
            black, blue, black, black, black, // linha 2
            black, black, black, blue, black, // linha 3
            black, black, black, black, black, // linha 4
            black, black, black, black, black, // linha 5

        },
        // 8° Frame - Parte 3.3
        { 
            blue, blue, blue, blue, black,    // linha 1
            black, blue, black, black, black, // linha 2
            black, black, black, blue, black, // linha 3
            black, blue, black, black, black, // linha 4
            black, black, black, black, black, // linha 5

        },
        // 9° Frame - Parte 3.4
        { 
            blue, blue, blue, blue, black,    // linha 1
            black, blue, black, black, black, // linha 2
            black, black, black, blue, black, // linha 3
            black, blue, black, black, black, // linha 4
            black, black, black, blue, black, // linha 5

        },

        // 10° Frame - Parte 4.1
        {
            blue, blue, blue, blue, black,    // linha 1
            black, blue, black, black, black, // linha 2
            black, black, black, blue, black, // linha 3
            black, blue, black, black, black, // linha 4
            black, black, black, blue, black,    // linha 5
        },
        // 11° Frame - Parte 4.2
        {
            blue, blue, blue, blue, black,    // linha 1
            black, blue, black, black, black, // linha 2
            black, black, black, blue, black, // linha 3
            black, blue, black, black, black, // linha 4
            black, black, blue, blue, black,    // linha 5
        },
        // 12° Frame - Parte 4.3
        {
            blue, blue, blue, blue, black,    // linha 1
            black, blue, black, black, black, // linha 2
            black, black, black, blue, black, // linha 3
            black, blue, black, black, black, // linha 4
            black, blue, blue, blue, black,    // linha 5
        },
        // 13° Frame - Parte 4.4
        {
            blue, blue, blue, blue, black,    // linha 1
            black, blue, black, black, black, // linha 2
            black, black, black, blue, black, // linha 3
            black, blue, black, black, black, // linha 4
            blue, blue, blue, blue, black,    // linha 5
        },

        // 14° Frame - Parte 5.1
        {
            blue, blue, blue, blue, black,    // linha 1
            black, blue, black, black, black, // linha 2
            black, black, black, blue, black,  // linha 3
            black, blue, black, black, blue,  // linha 4
            blue, blue, blue, blue, black,    // linha 5
        },
        // 15° Frame - Parte 5.2
        {
            blue, blue, blue, blue, black,    // linha 1
            black, blue, black, black, black, // linha 2
            blue, black, black, blue, black,  // linha 3
            black, blue, black, black, blue,  // linha 4
            blue, blue, blue, blue, black,    // linha 5
        },

        // 16° Frame - Parte 6.1
        {
            blue, blue, blue, blue, black,    // linha 1
            black, blue, black, black, black, // linha 2
            blue, blue, black, blue, black,     // linha 3
            black, blue, black, black, blue,  // linha 4
            blue, blue, blue, blue, black,    // linha 5
        },
        // 17° Frame - Parte 6.2
        {
            blue, blue, blue, blue, black,    // linha 1
            black, blue, black, black, black, // linha 2
            blue, blue, blue, blue, black,     // linha 3
            black, blue, black, black, blue,  // linha 4
            blue, blue, blue, blue, black,    // linha 5
        },
        // 18° Frame - Parte 6.3
        {
            blue, blue, blue, blue, black,    // linha 1
            black, blue, black, black, black, // linha 2
            blue, blue, blue, blue, blue,     // linha 3
            black, blue, black, black, blue,  // linha 4
            blue, blue, blue, blue, black,    // linha 5
        },

    };

    for (uint i = 0; i < 18; i++)
    {
        draw_pio(frames[i], pio, sm, intensity);
        sleep_ms(100);
    }
}