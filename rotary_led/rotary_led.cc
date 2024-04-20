#include "rotary_led.h"
#include "hardware/adc.h"
#include <stdio.h>

uint32_t const RotaryLed::delay = 50;

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
    auto analog_read = adc_read();
    uint16_t pin = (analog_read > 3410) ? 5
                 : (analog_read > 2728) ? 4
                 : (analog_read > 2046) ? 3
                 : (analog_read > 1364) ? 2
                 : (analog_read > 682) ? 1
                 : 0;
    mask = 1 << pins[pin];
    return mask;
}

void RotaryLed::clear()
{
    gpio_clr_mask(mask);
}