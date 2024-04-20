#include <array>
#include <initializer_list>
#include <cstdint>

class RotaryLed
{
private:
    /** @brief Digital pins needed to control the rotary led. Indices from zero to six corresponds to led pins A, B, C, D, E, F (G is never turned on). The last pin (index 7) must be the analog one. */
    std::array<uint32_t, 7> pins;
    /** @brief Binary code indicating the led to be turned on */
    uint32_t mask;
public:
    /** @brief The time the rotary led delays on reading the input */
    static uint32_t const delay;
    /** @brief Constructs the rotary led from an 7-uint array */
    RotaryLed(const std::array<uint32_t, 7>& _pins)
        : pins(_pins)
        , mask (0)
        { }
    /** @brief Constructs the rotary led from an initializer list */
    RotaryLed(std::initializer_list<uint32_t> _pins)
    {
        mask = 0;
        auto it = pins.begin();
        for (auto pin : _pins)
            *(it++) = pin;
    }
    /** @brief Initializes the pins the rotary led uses */
    void init();
    /** @brief Turns a led on depending on the read analog value */
    void turn_led_on();
    /** @brief Reads the analog value from the output of a potentiometer */
    uint32_t read_value();
    /** @brief Clears the seven segment display */
    void clear();
};