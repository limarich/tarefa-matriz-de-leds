#include "animations.h"
#include "keyboard.h"
// CORES PARA AS ANIMAÇÕES

const pixel black = {0, 0, 0};
const pixel white = {213, 210, 210};
const pixel green = {32, 216, 26};
const pixel dark_green = {6, 80, 36};
const pixel brown = {181, 68, 81};
const pixel red = {252, 6, 6};
const pixel roxo = {15, 0, 15};
const pixel orange = {255, 65, 0};
const pixel blue = {65, 105, 225};
const pixel yellow = {241, 255, 0};

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

void logo_embarcatech(PIO pio, uint sm, float intensity)
{
    frame frames[18] = {
        // 1° Frame
        {
            black, black, black, black, black, // linha 1
            black, black, black, black, black, // linha 2
            black, black, black, black, black, // linha 3
            black, black, black, black, black, // linha 4
            black, black, black, black, black, // linha 5
        },
        // 2°.1
        {
            blue, black, black, black, black,  // linha 1
            black, black, black, black, black, // linha 2
            black, black, black, black, black, // linha 3
            black, black, black, black, black, // linha 4
            black, black, black, black, black, // linha 5
        },
        // 2°.2
        {
            blue, blue, black, black, black,   // linha 1
            black, black, black, black, black, // linha 2
            black, black, black, black, black, // linha 3
            black, black, black, black, black, // linha 4
            black, black, black, black, black, // linha 5
        },
        // 2°.3
        {
            blue, blue, blue, black, black,    // linha 1
            black, black, black, black, black, // linha 2
            black, black, black, black, black, // linha 3
            black, black, black, black, black, // linha 4
            black, black, black, black, black, // linha 5
        },
        // 2°.4
        {
            blue, blue, blue, blue, black,     // linha 1
            black, black, black, black, black, // linha 2
            black, black, black, black, black, // linha 3
            black, black, black, black, black, // linha 4
            black, black, black, black, black, // linha 5
        },

        // Terceiro Parte
        // 3.1
        {
            blue, blue, blue, blue, black,     // linha 1
            black, blue, black, black, black,  // linha 2
            black, black, black, black, black, // linha 3
            black, black, black, black, black, // linha 4
            black, black, black, black, black, // linha 5

        },
        // 3.2
        {
            blue, blue, blue, blue, black,     // linha 1
            black, blue, black, black, black,  // linha 2
            black, black, black, blue, black,  // linha 3
            black, black, black, black, black, // linha 4
            black, black, black, black, black, // linha 5

        },
        // 3.3
        {
            blue, blue, blue, blue, black,     // linha 1
            black, blue, black, black, black,  // linha 2
            black, black, black, blue, black,  // linha 3
            black, blue, black, black, black,  // linha 4
            black, black, black, black, black, // linha 5

        },
        // 3.4
        {
            blue, blue, blue, blue, black,    // linha 1
            black, blue, black, black, black, // linha 2
            black, black, black, blue, black, // linha 3
            black, blue, black, black, black, // linha 4
            black, black, black, blue, black, // linha 5

        },

        // Quarto Frame
        // 4.1
        {
            blue, blue, blue, blue, black,    // linha 1
            black, blue, black, black, black, // linha 2
            black, black, black, blue, black, // linha 3
            black, blue, black, black, black, // linha 4
            black, black, black, blue, black, // linha 5
        },
        // 4.2
        {
            blue, blue, blue, blue, black,    // linha 1
            black, blue, black, black, black, // linha 2
            black, black, black, blue, black, // linha 3
            black, blue, black, black, black, // linha 4
            black, black, blue, blue, black,  // linha 5
        },
        // 4.3
        {
            blue, blue, blue, blue, black,    // linha 1
            black, blue, black, black, black, // linha 2
            black, black, black, blue, black, // linha 3
            black, blue, black, black, black, // linha 4
            black, blue, blue, blue, black,   // linha 5
        },
        // 4.4
        {
            blue, blue, blue, blue, black,    // linha 1
            black, blue, black, black, black, // linha 2
            black, black, black, blue, black, // linha 3
            black, blue, black, black, black, // linha 4
            blue, blue, blue, blue, black,    // linha 5
        },

        // Quinto Frame

        // 5.1
        {
            blue, blue, blue, blue, black,    // linha 1
            black, blue, black, black, black, // linha 2
            black, black, black, blue, black, // linha 3
            black, blue, black, black, blue,  // linha 4
            blue, blue, blue, blue, black,    // linha 5
        },
        // 5.2
        {
            blue, blue, blue, blue, black,    // linha 1
            black, blue, black, black, black, // linha 2
            blue, black, black, blue, black,  // linha 3
            black, blue, black, black, blue,  // linha 4
            blue, blue, blue, blue, black,    // linha 5
        },
        // 6.1
        {
            blue, blue, blue, blue, black,    // linha 1
            black, blue, black, black, black, // linha 2
            blue, blue, black, blue, black,   // linha 3
            black, blue, black, black, blue,  // linha 4
            blue, blue, blue, blue, black,    // linha 5
        },
        // 6.2
        {
            blue, blue, blue, blue, black,    // linha 1
            black, blue, black, black, black, // linha 2
            blue, blue, blue, blue, black,    // linha 3
            black, blue, black, black, blue,  // linha 4
            blue, blue, blue, blue, black,    // linha 5
        },
        // 6.3
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
        if (i == 17)
        {
            play_tone(BUZZER_A, 440, 100);
            sleep_ms(100);
            play_tone(BUZZER_A, 553, 300);
        }
        sleep_ms(100);
    }
}

void pacman(PIO pio, uint sm, float intensity)
{
    frame frames[10] = {
        {
            // linha 5
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            // linha 4
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            // linha 3
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            // linha 2
            yellow,
            blue,
            yellow,
            yellow,
            yellow,
            // linha 1
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
        },
        {
            // linha 5
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            // linha 4
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            // linha 3
            black,
            yellow,
            yellow,
            yellow,
            yellow,
            // linha 2
            yellow,
            blue,
            yellow,
            yellow,
            yellow,
            // linha 1
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
        },
        {
            // linha 5
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            // linha 4
            yellow,
            yellow,
            yellow,
            yellow,
            black,
            // linha 3
            black,
            black,
            yellow,
            yellow,
            yellow,
            // linha 2
            yellow,
            blue,
            yellow,
            yellow,
            black,
            // linha 1
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
        },
        {
            // linha 5
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            // linha 4
            yellow,
            yellow,
            yellow,
            black,
            black,
            // linha 3
            black,
            black,
            black,
            yellow,
            yellow,
            // linha 2
            yellow,
            blue,
            yellow,
            black,
            black,
            // linha 1
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
        },
        {
            // linha 5
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            // linha 4
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            // linha 3
            black,
            yellow,
            yellow,
            yellow,
            yellow,
            // linha 2
            yellow,
            blue,
            yellow,
            yellow,
            yellow,
            // linha 1
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
        },
        {
            // linha 5
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            // linha 4
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            // linha 3
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            // linha 2
            yellow,
            blue,
            yellow,
            yellow,
            yellow,
            // linha 1
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
        },
        {
            // linha 5
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            // linha 4
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            // linha 3
            black,
            yellow,
            yellow,
            yellow,
            yellow,
            // linha 2
            yellow,
            blue,
            yellow,
            yellow,
            yellow,
            // linha 1
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
        },
        {
            // linha 5
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            // linha 4
            yellow,
            yellow,
            yellow,
            yellow,
            black,
            // linha 3
            black,
            black,
            yellow,
            yellow,
            yellow,
            // linha 2
            yellow,
            blue,
            yellow,
            yellow,
            black,
            // linha 1
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
        },
        {
            // linha 5
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            // linha 4
            yellow,
            yellow,
            yellow,
            black,
            black,
            // linha 3
            black,
            black,
            black,
            yellow,
            yellow,
            // linha 2
            yellow,
            blue,
            yellow,
            black,
            black,
            // linha 1
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
        },
        {
            // linha 5
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            // linha 4
            yellow,
            yellow,
            yellow,
            yellow,
            yellow,
            // linha 3
            black,
            yellow,
            yellow,
            yellow,
            yellow,
            // linha 2
            yellow,
            blue,
            yellow,
            yellow,
            yellow,
            // linha 1
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

void bandeira(PIO pio, uint sm, float intensity)
{
    frame frames[24] = {
    // 1° frame
    {
        red,   black, black, black, black,
        black, black, black, black, black,
        black, black, black, black, black,
        black, black, black, black, black,
        black, black, black, black, black,
    },
    // 2° frame
    {
        red,   red,   black, black, black,
        black, black, black, black, black,
        black, black, black, black, black,
        black, black, black, black, black,
        black, black, black, black, black,
    },
    // 3° frame
    {
        red,   red,   red,   black, black,
        black, black, black, black, black,
        black, black, black, black, black,
        black, black, black, black, black,
        black, black, black, black, black,
    },
    // 4° frame
    {
        red,   red,   red,   red,   black,
        black, black, black, black, black,
        black, black, black, black, black,
        black, black, black, black, black,
        black, black, black, black, black,
    },
    // 5° frame
    {
        red,   red,   red,   red,   red,
        black, black, black, black, black,
        black, black, black, black, black,
        black, black, black, black, black,
        black, black, black, black, black,
    },
    // 6° frame
    {
        red,   red,   red,   red,   red,
        red,   black, black, black, black,
        black, black, black, black, black,
        black, black, black, black, black,
        black, black, black, black, black,
    },
    // 7° frame
    {
        red,   red,   red,   red,   red,
        red,   red,   black, black, black,
        black, black, black, black, black,
        black, black, black, black, black,
        black, black, black, black, black,
    },
    // 8° frame
    {
        red,   red,   red,   red,   red,
        red,   red,   red,   black, black,
        black, black, black, black, black,
        black, black, black, black, black,
        black, black, black, black, black,
    },
    // 9° frame
    {
        red,   red,   red,   red,   red,
        red,   red,   red,   red,   black,
        black, black, black, black, black,
        black, black, black, black, black,
        black, black, black, black, black,
    },
    // 10° frame (linha vermelha completa)
    {
        red,   red,   red,   red,   red,
        red,   red,   red,   red,   red,
        black, black, black, black, black,
        black, black, black, black, black,
        black, black, black, black, black,
    },
    // 11° frame (linha branca começa)
    {
        red,   red,   red,   red,   red,
        red,   red,   red,   red,   red,
        white, black, black, black, black,
        black, black, black, black, black,
        black, black, black, black, black,
    },
    // 12° frame (linha branca continua)
    {
        red,   red,   red,   red,   red,
        red,   red,   red,   red,   red,
        white, white, black, black, black,
        black, black, black, black, black,
        black, black, black, black, black,
    },
    // 13° frame (linha branca continua)
    {
        red,   red,   red,   red,   red,
        red,   red,   red,   red,   red,
        white, white, white, black, black,
        black, black, black, black, black,
        black, black, black, black, black,
    },
    // 14° frame (linha branca completa)
    {
        red,   red,   red,   red,   red,
        red,   red,   red,   red,   red,
        white, white, white, white, white,
        black, black, black, black, black,
        black, black, black, black, black,
    },
    // 15° frame (linha azul começa)
    {
        red,   red,   red,   red,   red,
        red,   red,   red,   red,   red,
        white, white, white, white, white,
        blue,   black, black, black, black,
        black, black, black, black, black,
    },
    // 16° frame (linha azul continua)
    {
        red,   red,   red,   red,   red,
        red,   red,   red,   red,   red,
        white, white, white, white, white,
        blue,  blue,  black, black, black,
        black, black, black, black, black,
    },
    // 17° frame (linha azul continua)
    {
        red,   red,   red,   red,   red,
        red,   red,   red,   red,   red,
        white, white, white, white, white,
        blue,  blue,   blue,   black, black,
        black, black, black, black, black,
    },
    // 18° frame (linha azul continua)
    {
        red,   red,   red,   red,   red,
        red,   red,   red,   red,   red,
        white, white, white, white, white,
        blue,   blue,   blue,   blue,  black,
        black, black, black, black, black,
    },
    // 19° frame (linha azul continua)
    {
        red,   red,   red,   red,   red,
        red,   red,   red,   red,   red,
        white, white, white, white, white,
        blue,  blue,  blue,   blue,  blue,
        black, black, black, black, black,
    },
    // 20° frame (linha azul continua)
    {
        red,   red,   red,   red,   red,
        red,   red,   red,   red,   red,
        white, white, white, white, white,
        blue,  blue,   blue,   blue,  blue,
        blue, black, black, black, black,
    },
    // 21° frame (linha azul continua)
    {
        red,   red,   red,   red,   red,
        red,   red,   red,   red,   red,
        white, white, white, white, white,
        blue,   blue,   blue,   blue,  blue,
        blue, blue, black, black, black,
    },
    // 22° frame (linha azul continua)
    {
        red,   red,   red,   red,   red,
        red,   red,   red,   red,   red,
        white, white, white, white, white,
        blue,   blue,   blue,   blue,  blue,
        blue, blue, blue, black, black,
    },
    // 23° frame (linha azul continua)
    {
        red,   red,   red,   red,   red,
        red,   red,   red,   red,   red,
        white, white, white, white, white,
        blue,  blue,  blue,   blue,  blue,
        blue, blue, blue, blue,  black,
    },
    // 24° frame (linha azul completa)
    {
        red,   red,   red,   red,   red,
        red,   red,   red,   red,   red,
        white, white, white, white, white,
        blue,  blue,  blue,  blue,  blue,
        blue,  blue,  blue,  blue,  blue,
    },
};
for (uint i = 0; i < 19; i++)
    {
        draw_pio(frames[i], pio, sm, intensity);
        sleep_ms(100);
    }
    draw_pio(frames[23], pio, sm, intensity);
    play_tone(BUZZER_A, 261, 400); // Frequência de 261 Hz por 500 ms nota Dó
    sleep_ms(80);
    for (uint i = 0; i < 2; i++)
    {
    play_tone(BUZZER_A, 261, 180);
    sleep_ms(60);
    }
    play_tone(BUZZER_A, 261, 250);
    sleep_ms(100);
    play_tone(BUZZER_A, 329, 300); // nota mi
    sleep_ms(50);
    play_tone(BUZZER_A, 261, 300);
    sleep_ms(50);
    play_tone(BUZZER_A, 392, 300); // nota sol
    sleep_ms(50);
    play_tone(BUZZER_A, 329, 300); // nota mi
    sleep_ms(50);
    play_tone(BUZZER_A, 261, 300);
    sleep_ms(50);
    play_tone(BUZZER_A, 392, 300); // nota 
    sleep_ms(300);
}

