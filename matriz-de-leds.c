#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "libs/leds.h"
#include "pico/stdlib.h"
#include "libs/buzzer.h"
#include "hardware/pio.h"
#include "hardware/adc.h"
#include "pico/bootrom.h"
#include "hardware/pwm.h"
#include "libs/keyboard.h"
#include "pio_matrix.pio.h"
#include "hardware/clocks.h"
#include "libs/animations.h"

#define clear_terminal printf("\033[H\033[J");
// botão de interupção
const uint button_0 = 5;
const uint button_1 = 6;

// rotina da interrupção
static void gpio_irq_handler(uint gpio, uint32_t events)
{
    printf("Interrupção ocorreu no pino %d, no evento %d\n", gpio, events);
    printf("HABILITANDO O MODO GRAVAÇÃO");
    reset_usb_boot(0, 0); // habilita o modo de gravação do microcontrolador
}
// variáveis globais
float intensity = 0.5f;
PIO pio;
uint sm;

void select_action(char key);
void show_menu();

// função principal
int main()
{
    pio = pio0;
    bool ok;
    uint16_t i;
    double r = 0.0, b = 0.0, g = 0.0;
    frame draw;

    // coloca a frequência de clock para 128 MHz, facilitando a divisão pelo clock
    ok = set_sys_clock_khz(128000, false);

    // Inicializa todos os códigos stdio padrão que estão ligados ao binário.
    stdio_init_all();

    // configuração do teclado
    setup_keyboard();

    printf("iniciando a transmissão PIO");
    if (ok)
        printf("clock set to %ld\n", clock_get_hz(clk_sys));

    // configurações da PIO
    uint offset = pio_add_program(pio, &pio_matrix_program);
    sm = pio_claim_unused_sm(pio, true);
    pio_matrix_program_init(pio, sm, offset, LED_PIN);

    // inicializar o botão de interrupção - GPIO5
    gpio_init(button_0);
    gpio_set_dir(button_0, GPIO_IN);
    gpio_pull_up(button_0);

    // inicializar o botão de interrupção - GPIO5
    gpio_init(button_1);
    gpio_set_dir(button_1, GPIO_IN);
    gpio_pull_up(button_1);

    // interrupção da gpio habilitada
    gpio_set_irq_enabled_with_callback(button_0, GPIO_IRQ_EDGE_FALL, 1, &gpio_irq_handler);

    initialization_buzzers(BUZZER_A, BUZZER_B);
    setup_keyboard();
    show_menu();
    while (true)
    {

        char key = scan_keypad();
        if (key != '\0')
        {
            select_action(key);
            clear_terminal
            show_menu();
        }
        sleep_ms(10);
    }
}

void show_menu()
{
    printf("\n=========================================\n");
    printf("           MENU DE OPÇÕES               \n");
    printf("=========================================\n");
    printf(" Escolha uma ação pelo teclado:         \n");
    printf("-----------------------------------------\n");
    printf(" [0-9]  → Selecionar Animação           \n");
    printf(" [A]    → Desligar todos os LEDs        \n");
    printf(" [B]    → Acender LEDs AZUL (100%%)      \n");
    printf(" [C]    → Acender LEDs VERMELHO (80%%)   \n");
    printf(" [D]    → Acender LEDs VERDE (50%%)      \n");
    printf(" [#]    → Acender LEDs BRANCO (20%%)     \n");
    printf(" [*]    → Encerrar programa e gravação  \n");
    printf("-----------------------------------------\n");
    printf(" Pressione uma tecla para continuar...  \n");
    printf("=========================================\n\n");
}

void select_action(char key)
{
    switch (key)
    {
    case '0':
        printf("Animação 0 selecionada\n");
        draw_smile(pio0, sm, intensity);
        break;
    case '1':
        printf("Animação 1 selecionada\n");
        draw_numbers(pio0, sm, intensity);
        break;
    case '2':
        printf("Animação 2 selecionada\n");
        logo_embarcatech(pio, sm, intensity);
        break;
    case '3':
        printf("Animação 3 selecionada\n");
        pacman(pio, sm, intensity);
        break;
    case '4':
        printf("Animação 4 selecionada\n");
        draw_rocket_animation(pio, sm, intensity);
        break;
    case '5':
        printf("Animação 5 selecionada\n");
        formula1_semaphore(pio, sm, intensity);
        break;
    case '6':
        printf("Animação 6 selecionada\n");
        break;
    case '7':
        printf("Animação 7 selecionada\n");
        break;
    case '8':
        printf("Animação 8 selecionada\n");
        break;
    case '9':
        printf("Animação 9 selecionada\n");
        break;
    case '*':
        printf("Encerrando o programa e entrando em modo de gravação\n");
        reset_usb_boot(0, 0);
        break;
    default:
        break;
    }
    // reset nos leds
    reset_leds(pio0, sm);
}
