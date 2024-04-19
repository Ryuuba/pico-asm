#include "rotary_led.h"
#include "hardware/adc.h"
#include <stdio.h>


void RotaryLed::init()
{
    // Initilizes digital output
    for (auto it = pins.begin(); it < pins.end() - 1; it++)
    {
        gpio_init(*it);
        gpio_set_dir(*it, GPIO_OUT);
    }

    // Initializes analog input
    adc_init();
    assert(pins.back() >= 26 || pins.back() <= 29);
    adc_gpio_init(pins.back());
    adc_select_input(0); // TODO: select the appropriate analog channel
}

void RotaryLed::turn_led_on()
{
    gpio_set_mask(mask);
}

uint32_t RotaryLed::read_value()
{
    static uint8_t pin = 0;
    mask = 1 << pins[pin];
    printf("pin: %i, mask: %i\n", pins[pin], mask);
    pin = (pin + 1)%6;
    return mask;
}

void RotaryLed::clear()
{
    gpio_clr_mask(mask);
}