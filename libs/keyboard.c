#include "keyboard.h"

// Mapeamento dos caracteres para Código Morse
const char *morse_code[ROWS][COLS] = {
    {".----", "..---", "...--", ".-"},   // 1, 2, 3, A
    {"....-", ".....", "-....", "-..."}, // 4, 5, 6, B
    {"--...", "---..", "----.", "-.-."}, // 7, 8, 9, C
    {NULL, "-----", NULL, "-.--"}        // *, 0, #, D
};

const uint ROW_PINS[ROWS] = {2, 3, 8, 9};
const uint COL_PINS[COLS] = {20, 19, 18, 17};

const char KEYPAD[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

void setup_keyboard(void)
{
    for (int i = 0; i < ROWS; i++)
    {
        gpio_init(ROW_PINS[i]);
        gpio_set_dir(ROW_PINS[i], GPIO_OUT);
        gpio_put(ROW_PINS[i], 1); // nível alto por padrão
    }

    for (int i = 0; i < COLS; i++)
    {
        gpio_init(COL_PINS[i]);
        gpio_set_dir(COL_PINS[i], GPIO_IN);
        gpio_pull_up(COL_PINS[i]);
    }
}

void setup_keyboard_with_interrupt()
{
    for (int i = 0; i < ROWS; i++)
    {
        gpio_init(ROW_PINS[i]);
        gpio_set_dir(ROW_PINS[i], GPIO_OUT);
        gpio_put(ROW_PINS[i], 1); // nível alto por padrão
    }

    for (int i = 0; i < COLS; i++)
    {
        gpio_init(COL_PINS[i]);
        gpio_set_dir(COL_PINS[i], GPIO_IN);
        gpio_pull_up(COL_PINS[i]);

        // Habilitar interrupção para todas as colunas
        gpio_set_irq_enabled(COL_PINS[i], GPIO_IRQ_EDGE_FALL, true);
    }
}

char scan_keypad(void)
{
    for (int row = 0; row < ROWS; row++)
    {
        gpio_put(ROW_PINS[row], 0); // Ativa a linha colocando em LOW
        for (int col = 0; col < COLS; col++)
        {
            if (!gpio_get(COL_PINS[col]))
            {
                gpio_put(ROW_PINS[row], 1); // Restaura a linha para HIGH
                return KEYPAD[row][col];    // Retorna a tecla pressionada
            }
        }
        gpio_put(ROW_PINS[row], 1); // Restaura linha após verificação
    }
    return '\0'; // Nenhuma tecla pressionada
}

const char *get_morse_from_key(char key)
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (KEYPAD[row][col] == key)
            {
                return morse_code[row][col];
            }
        }
    }
    return NULL; // Retorna NULL se a tecla não tiver código Morse associado
}

bool is_key_pressed(char key)
{
    return scan_keypad() == key;
}
