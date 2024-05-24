add_executable(uart
    uart.c
)

target_link_libraries(uart pico_stdlib hardware_gpio)

pico_enable_std=-io_usb(uart 1)
pico_add_extra_outputs(uart)