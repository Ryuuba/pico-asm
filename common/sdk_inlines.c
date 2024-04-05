#include "hardware/gpio.h"

/*
 * These functions are placeholders for SDK functions
 * that are marked as inline, ie. to be compiled in place.
 */

void gpio_set_dir_wrapper(int pin, int direction) {
    gpio_set_dir(pin, direction);
}

void gpio_put_wrapper(int pin, int state) {
    gpio_put(pin, state);
}

void gpio_pull_up_wrapper(uint gpio) {
    gpio_pull_up(gpio);
}
bool gpio_get_wrapper(uint gpio) {
    return gpio_get(gpio);
}

void gpio_set_mask_wrapper(uint32_t mask) {
    gpio_set_mask(mask);
}

void gpio_clr_mask_wrapper(uint32_t mask) {
    gpio_clr_mask(mask);
}