#include "crotaryled.h"
#include "hardware/adc.h"

void rl_construct(const int a[])
{
    for (int i = 0; i < PINS_SIZE - 1; i++)
        pins[i] = a[i];
    rl_mask = 0;
}

void rl_init()
{
    // Initilizes digital output
    for (int i = 0; i < PINS_SIZE; i++)
    {
        gpio_init(pins[i]);
        gpio_set_dir(pins[i], GPIO_OUT);
    }

    // Initializes analog input
    adc_init();
    adc_gpio_init(pins[6]);
    adc_select_input(0); 
}

void rl_turn_led_on()
{
    gpio_set_mask(rl_mask);
}

uint32_t rl_read_value()
{
    auto analog_read = adc_read();
    uint16_t pin = (analog_read > 3410) ? 5
                 : (analog_read > 2728) ? 4
                 : (analog_read > 2046) ? 3
                 : (analog_read > 1364) ? 2
                 : (analog_read > 682) ? 1
                 : 0;
    rl_mask = 1 << pins[pin];
    return rl_mask;
}

void rl_clear()
{
    gpio_clr_mask(rl_mask);
}