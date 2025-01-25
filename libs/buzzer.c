#include "buzzer.h"

// Inicializa os buzzers a serem utilizados
void initialization_buzzers(uint gpio_buzzer_a, uint gpio_buzzer_b)
{
    gpio_init(gpio_buzzer_a);
    gpio_set_dir(gpio_buzzer_a, GPIO_OUT);
    gpio_put(gpio_buzzer_a, 0);

    gpio_init(gpio_buzzer_b);
    gpio_set_dir(gpio_buzzer_b, GPIO_OUT);
    gpio_put(gpio_buzzer_b, 0);
}

// Configura e ativa o PWM para controlar o buzzer
void buzzer_pwm(uint gpio, uint16_t frequency, uint16_t duration_ms)
{
    gpio_set_function(gpio, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(gpio);

    pwm_set_wrap(slice, 125000000 / frequency);
    pwm_set_chan_level(slice, PWM_CHAN_A, (125000000 / frequency) / 2);
    pwm_set_enabled(slice, true);

    sleep_ms(duration_ms);

    pwm_set_enabled(slice, false);
    gpio_set_function(gpio, GPIO_FUNC_SIO);
    gpio_set_dir(gpio, GPIO_OUT);
    gpio_put(gpio, 0);
}

// Toca uma sequência de código Morse
void play_morse_code(const char *morse, uint gpio_buzzer_dot, uint gpio_buzzer_dash)
{
    for (size_t i = 0; i < strlen(morse); i++)
    {
        if (morse[i] == '.')
        {
            buzzer_pwm(gpio_buzzer_dot, 5280, 100); // Ponto
        }
        else if (morse[i] == '-')
        {
            buzzer_pwm(gpio_buzzer_dash, 5280, 300); // Traço
        }
        sleep_ms(100); // Intervalo entre pontos/traços
    }
    sleep_ms(300); // Intervalo entre letras
}

// Gera um som com a frequência especificada por um tempo determinado
void play_tone(uint gpio, uint frequency, uint duration_ms)
{
    if (frequency == 0)
        return;

    uint period = 1000000 / frequency;
    uint half_period = period / 2;

    for (uint i = 0; i < (duration_ms * 1000) / period; i++)
    {
        gpio_put(gpio, 1);
        sleep_us(half_period);
        gpio_put(gpio, 0);
        sleep_us(half_period);
    }
}
