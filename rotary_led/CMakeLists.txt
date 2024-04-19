add_executable(rotary_led
    rotary_led.cc
    test.cc
)
target_include_directories(rotary_led
    PRIVATE
    ../include)

target_link_libraries(rotary_led pico_stdlib hardware_gpio hardware_adc)

pico_enable_stdio_usb(rotary_led 1)
pico_enable_stdio_uart(rotary_led 0)
pico_add_extra_outputs(rotary_led)