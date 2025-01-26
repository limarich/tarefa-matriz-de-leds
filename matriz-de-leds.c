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

// variáveis globais
float intensity = 0.5f;
PIO pio;
uint sm;
volatile bool reset_leds_flag = 0;
volatile bool stop_animation = false;
volatile bool is_animation_running = false;

void select_action(char key);
void show_menu();

// rotina da interrupção
static void gpio_irq_handler(uint gpio, uint32_t events)
{
    printf("\n[DEBUG] Interrupção detectada no pino: %d\n", gpio);

    // Verifica qual botão foi pressionado
    if (gpio == button_0)
    {
        printf("Botão 0 pressionado → Entrando em modo de gravação...\n");
        reset_usb_boot(0, 0); // Entra no modo de gravação
    }
    else if (gpio == button_1)
    {
        stop_animation = true;
        reset_leds_flag = true;
        printf("Botão 1 pressionado → Resetando LEDs...\n");
        // if (is_animation_running)
        // {
        //     reset_leds_flag = 1;
        //     stop_animation = true;
        // }
    }
    else // Se for uma interrupção do teclado
    {
        stop_animation = true;
        reset_leds_flag = true;
        printf("interrupção do teclado\n");
        // if (is_animation_running)
        // {
        //     reset_leds_flag = 1;
        //     stop_animation = true;
        // }
    }

    // Reconhece a interrupção para evitar bloqueios
    gpio_acknowledge_irq(gpio, events);
}

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
    gpio_set_irq_enabled_with_callback(button_0, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled(button_1, GPIO_IRQ_EDGE_FALL, true);
    // 20, 19, 18, 17
    gpio_set_irq_enabled(20, GPIO_IRQ_EDGE_RISE, true);
    gpio_set_irq_enabled(19, GPIO_IRQ_EDGE_RISE, true);
    gpio_set_irq_enabled(18, GPIO_IRQ_EDGE_RISE, true);
    gpio_set_irq_enabled(17, GPIO_IRQ_EDGE_RISE, true);

    initialization_buzzers(BUZZER_A, BUZZER_B);
    setup_keyboard_with_interrupt();
    show_menu();

    while (true)
    {
        if (reset_leds_flag)
        {
            reset_leds(pio, sm);
            reset_leds_flag = false;
            sleep_ms(100);
        }

        char key = scan_keypad();
        if (key != '\0')
        {
            stop_animation = false;
            printf("iniciando ação selecionada...\n");
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
    if (is_animation_running)
    {
        printf("[INFO] Uma animação já está rodando. Aguarde ou pressione outra tecla para interromper.\n");
        return;
    }

    is_animation_running = true; // **Indica que uma animação está rodando**
    stop_animation = false;      // **Garante que o estado está correto antes de iniciar**

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
        break;
    case '3':
        printf("Animação 3 selecionada\n");
        break;
    case '4':
        printf("Animação 4 selecionada\n");
        break;
    case '5':
        printf("Animação 5 selecionada\n");
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

    is_animation_running = false;
}
