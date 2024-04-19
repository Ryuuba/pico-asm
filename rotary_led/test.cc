#include "rotary_led.h"
#include "pin_list.h"

int main()
{
    RotaryLed rotaryLed {
        PIN_A,
        PIN_B,
        PIN_C,
        PIN_D,
        PIN_E,
        PIN_F,
        PIN_G,
        ANALOG_PIN
    };
    return 0;
}