#define UART_TX_PIN 12
#define UART_RX_PIN 13

#define UART_ID uart0
#define BAUD_RATE 9600

#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "string.h"

int main()
{
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    uint8_t buffer[5];
    while (true)
    {
        // sends a command to the receiver
        uart_puts(UART_ID, "Hola");
        // waits for response world
        //TODO: Add interrupt to break the loop
        uart_read_blocking(UART_ID, buffer, 5);
        printf(buffer, " Hola %s", buffer);
    }
}