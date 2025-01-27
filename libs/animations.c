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
const pixel gray = {169, 169, 169};

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

void draw_rocket_animation(PIO pio, uint sm, float intensity) {
    frame frames[8] = {
        // Frame 1: Foguete na base
       {
        black, yellow, orange, yellow, black,
        black, gray, gray, gray, black,
        black, white, blue, white, black,
        black, black, white, black, black,
        black, black, black, black, black,
    },
    // Frame 2 
    {
        black, red, red, red, black,
        black, yellow, orange, yellow, black,
        black, gray, gray, gray, black,
        black, white, blue, white, black,
        black, black, white, black, black,
    },
    // Frame 3 
    {
        black, black, black, black, black,
        black, red, red, red, black,
        black, yellow, orange, yellow, black,
        black, gray, gray, gray, black,
        black, white, blue, white, black,
    },
    // Frame 4 
    {
        black, black, white, black, black,
        black, black, black, black, black,
        black, red, red, red, black,
        black, yellow, orange, yellow, black,
        black, gray, gray, gray, black,
    },
    // Frame 5 
    {
        black, white, blue, white, black,
        black, black, white, black, black,
        black, black, black, black, black,
        black, red, orange, red, black,
        black, yellow, orange, yellow, black,
    },
    // Frame 6 
    {
        black, gray, gray, gray, black,
        black, white, blue, white, black,
        black, black, white, black, black,
        black, black, black, black, black,
        black, red, red, red, black,
    },
    // Frame 7
    {
        black, yellow, orange, yellow, black,
        black, gray, gray, gray, black,
        black, white, blue, white, black,
        black, black, white, black, black,
        black, black, black, black, black,
    },
};

    // Exibição da animação
    for (int i = 0; i < 7; i++) { // Exibe cada frame uma vez
        draw_pio(frames[i], pio, sm, intensity); // Mostra o frame atual
       
        // Sons simples que fazem sentido para um foguete
        if (i < 4) {
            play_tone(BUZZER_A, 200 + i * 50, 300); // Sons crescentes durante a subida
        } else if (i == 4 || i == 5) {
            play_tone(BUZZER_A, 100, 300); // Sons graves para a chama
        }
        
        sleep_ms(700); // Troca de frame a cada 700 ms
    }
}

