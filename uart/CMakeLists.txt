add_executable(uart
    uart.c
)

target_link_libraries(uart pico_stdlib hardware_gpio)

pico_enable_stdio_usb(uart 1)
pico_enable_stdio_uart(uart 0)
pico_add_extra_outputs(uart)