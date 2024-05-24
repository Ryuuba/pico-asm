#define UART_TX_PIN 12
#define UART_RX_PIN 13

#define UART_ID uart0
#define BAUD_RATE 9600
#define BUTTON_GPIO 15
#define LED 16

#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "hardware/gpio.h"

int main()
{
    uint8_t cmd = 0;
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    gpio_init(BUTTON_GPIO);
    gpio_set_dir(BUTTON_GPIO, GPIO_IN);
    gpio_pull_up(BUTTON_GPIO);

    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);
    gpio_put(LED, 0);
    while (true)
    {
        if (!gpio_get(BUTTON_GPIO)) {
            gpio_put(LED, 1);
            // sends a command to the receiver
            uart_putc(UART_ID, cmd+0x30);
            cmd = (cmd + 1) & 3;
            sleep_ms(1000);
        }
        gpio_put(LED, 0);
    }
}