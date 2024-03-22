add_executable(arithmetic-logic
    arithmetic-logic.S
    ../common/sdk_inlines.c
)

target_link_libraries(arithmetic-logic pico_stdlib hardware_gpio)

pico_enable_stdio_usb(arithmetic-logic 1)
pico_enable_stdio_uart(arithmetic-logic 0)
pico_add_extra_outputs(arithmetic-logic)