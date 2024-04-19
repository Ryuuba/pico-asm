#include <stdio.h>
#include "pico/stdlib.h"
#include "rotary_led.h"
#include "pin_list.h"

int main()
{
    RotaryLed rotaryLed {PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, ANALOG_PIN};
    stdio_init_all();
    rotaryLed.init();
    while (true)
    {
        auto val = rotaryLed.read_value();
        printf("mask: %i\n",val);
        rotaryLed.turn_led_on();
        sleep_ms(500);
        rotaryLed.clear();
    }
    return 0;
}