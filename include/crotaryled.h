#ifndef C_ROTARY_LED_H
#define C_ROTARY_LED_H

#include <stdint.h>
#define PINS_SIZE 7

/** @brief Digital pins needed to control the rotary led. Indices from zero to six corresponds to led pins A, B, C, D, E, F (G is never turned on). The last pin (index 7) must be the analog one. */
static uint32_t pins[PINS_SIZE];

/** @brief The value indicating the leds to be turned on */
static uint32_t rl_mask;

/** @brief The time the rotary led delays the reading of the input */
static uint32_t const rl_delay = 50;

/** @brief Initializes the pins the rotary led uses */
void rl_construct(const int a[]);

/** @brief Initializes the pins the rotary led uses */
void rl_init();

/** @brief Turns a led on depending on the read analog value */
void rl_turn_led_on();

/** @brief Reads the analog value from the output of a potentiometer */
uint32_t rl_read_value();

/** @brief Clears the seven segment display */
void rl_clear();

#endif