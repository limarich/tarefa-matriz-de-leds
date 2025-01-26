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
float intensity = 0.3f;
// função principal
int main()
{
    PIO pio = pio0;
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
    uint sm = pio_claim_unused_sm(pio, true);
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
    int key = 4;

    while (true)
    {
        printf("\nfrequência de clock %ld\r\n", clock_get_hz(clk_sys));
        draw_smile(pio, sm, intensity);
        logo_embratech(pio, sm, intensity);

        sleep_ms(1000);
        if (key == 4) 
        {
            draw_numbers(pio, sm, intensity);
            sleep_ms(500);
        }
    }
}
