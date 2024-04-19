#include "rotary_led.h"
#include "hardware/adc.h"



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
    uint8_t pin = adc_read() % 7;
    mask = 1 << pins[pin];
    return mask;
}