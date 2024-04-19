#include <array>
#include <initializer_list>
#include <cstdint>

class RotaryLed
{
private:
    /** @brief Digital pins needed to control the Rotary led. Indices from zero to 6 corresponds to led pins A, B, C, D, E, F y G. The last pin (index 7) must be the analog one. */
    std::array<uint32_t, 8> pins;
    /** @brief The led to be turned on */
    uint32_t mask;
public:
    /** @brief Constructs the rotary led from an 8-int array */
    RotaryLed(const std::array<uint32_t, 8>& _pins)
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
};