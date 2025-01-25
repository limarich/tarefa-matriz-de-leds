# Documentação das Bibliotecas de LEDs, Buzzer e Teclados Matriciais

## Biblioteca de LEDs
A biblioteca de LEDs foi projetada para controlar uma matriz de LEDs utilizando o protocolo WS2812B. Com a finalidade de abstrair o código e facilitar a legibilidade, esta biblioteca ainda fornece o tipo `frame` que representa uma matriz de 25 pixels contendo, cada um, um valor de red, green e blue.

### Funções Disponíveis

#### **matrix_rgb**
Essa função define a intensidade e a composição de cores de um LED RGB.

```c
uint32_t matrix_rgb(uint r, uint g, uint b, float intensity);
```

- **Parâmetros:**
  - `r`: Valor do vermelho (0 a 255).
  - `g`: Valor do verde (0 a 255).
  - `b`: Valor do azul (0 a 255).
  - `intensity`: Intensidade da cor (0.0 a 1.0).

- **Retorno:**
  - Um valor de 32 bits representando a cor no formato utilizado pelo WS2812B.

#### **draw_pio**
Rotina para acionar uma matriz de LEDs WS2812B utilizando o PIO (Programmable Input/Output) do microcontrolador.

```c
void draw_pio(pixel *draw, PIO pio, uint sm, float intensity);
```

- **Parâmetros:**
  - `draw`: Array de estruturas `pixel` representando os LEDs.
  - `pio`: Instância do PIO a ser usada.
  - `sm`: State machine configurada para operar o WS2812B.
  - `intensity`: Intensidade global para os LEDs.

- **Descrição:**
  - Cada LED na matriz é configurado de acordo com os valores RGB e intensidade fornecidos. A função envia os dados para o PIO de forma a atualizar a matriz.

---

## Biblioteca de Buzzer
A biblioteca de buzzer controla tons e sons utilizando um pino GPIO configurado para PWM (Pulse Width Modulation).

### Funções Disponíveis

#### **initialization_buzzers**
Inicializa os buzzers a serem utilizados.

```c
void initialization_buzzers(uint gpio_buzzer_a, uint gpio_buzzer_b);
```

- **Parâmetros:**
  - `gpio_buzzer_a`: GPIO do primeiro buzzer.
  - `gpio_buzzer_b`: GPIO do segundo buzzer.

- **Descrição:**
  - Configura os pinos GPIO como saída e os inicializa no nível baixo.

#### **buzzer_pwm**
Configura e ativa o PWM para controlar o buzzer.

```c
void buzzer_pwm(uint gpio, uint16_t frequency, uint16_t duration_ms);
```

- **Parâmetros:**
  - `gpio`: GPIO conectado ao buzzer.
  - `frequency`: Frequência do som em Hertz.
  - `duration_ms`: Duração do som em milissegundos.

- **Descrição:**
  - Configura o GPIO como saída PWM, ajusta a frequência e a duração do som, e restaura o pino ao final.

#### **play_morse_code**
Toca uma sequência de código Morse.

```c
void play_morse_code(const char *morse, uint gpio_buzzer_dot, uint gpio_buzzer_dash);
```

- **Parâmetros:**
  - `morse`: String contendo o código Morse a ser reproduzido ("." para ponto e "-" para traço).
  - `gpio_buzzer_dot`: GPIO para sons curtos.
  - `gpio_buzzer_dash`: GPIO para sons longos.

- **Descrição:**
  - Reproduz pontos e traços em sequência com intervalos configurados.

#### **play_tone**
Gera um som com a frequência especificada por um tempo determinado.

```c
void play_tone(uint gpio, uint frequency, uint duration_ms);
```

- **Parâmetros:**
  - `gpio`: GPIO conectado ao buzzer.
  - `frequency`: Frequência do som em Hertz.
  - `duration_ms`: Duração do som em milissegundos.

---

## Biblioteca de Teclados Matriciais
Esta biblioteca gerencia a entrada de dados por meio de um teclado matricial.

### Funções Disponíveis

#### **setup_keyboard**
Configura os pinos GPIO do teclado.

```c
void setup_keyboard(void);
```

- **Descrição:**
  - Configura os pinos das linhas como saída e os das colunas como entrada com pull-up.

#### **scan_keypad**
Realiza a leitura do teclado matricial para detectar a tecla pressionada.

```c
char scan_keypad(void);
```

- **Retorno:**
  - Caractere correspondente à tecla pressionada ou `\0` se nenhuma tecla estiver pressionada.

#### **get_morse_from_key**
Obtém o código Morse associado a uma tecla pressionada.

```c
const char *get_morse_from_key(char key);
```

- **Parâmetros:**
  - `key`: Tecla pressionada.

- **Retorno:**
  - Código Morse correspondente ou `NULL` se não houver associação.

#### **is_key_pressed**
Verifica se uma tecla específica está pressionada.

```c
bool is_key_pressed(char key);
```

- **Parâmetros:**
  - `key`: Tecla a ser verificada.

- **Retorno:**
  - `true` se a tecla estiver pressionada, caso contrário `false`.

---

Se precisar de mais detalhes ou tiver dúvidas sobre a utilização das bibliotecas, fique à vontade para entrar em contato!

