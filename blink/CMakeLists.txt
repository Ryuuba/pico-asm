add_executable(blink
    blink.S
    ../common/sdk_inlines.c
)

target_link_libraries(blink pico_stdlib hardware_gpio)

pico_enable_stdio_usb(blink 1)
pico_enable_stdio_uart(blink 0)
pico_add_extra_outputs(blink)