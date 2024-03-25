add_executable(Fibonacci
    Fibonacci.S
    ../common/sdk_inlines.c
)

target_link_libraries(Fibonacci pico_stdlib hardware_gpio)

pico_enable_stdio_usb(Fibonacci 1)
pico_enable_stdio_uart(Fibonacci 0)
pico_add_extra_outputs(Fibonacci)