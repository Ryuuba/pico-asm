#include "crotaryled.h"
#include "pico/stdlib.h"
#include "pin_list.h"
#include <stdio.h>

int main()
{
    int pins[] = {PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, ANALOG_PIN};
    rl_construct(pins);
    stdio_init_all();
    rl_init();
    while(true)
    {
        uint32_t val = rl_read_value();
        printf("mask: %i\n",val);
        rl_turn_led_on();
        sleep_ms(rl_delay);
        rl_clear();
    }
    return 0;
}