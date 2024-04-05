add_executable(hello_7segment
    ../common/sdk_inlines.c
    hello_7segment.S
        )

# pull in common dependencies
target_link_libraries(hello_7segment pico_stdlib)

# create map/bin/hex file etc.
pico_enable_stdio_usb(hello_7segment 1)
pico_enable_stdio_uart(hello_7segment 0)
pico_add_extra_outputs(hello_7segment)
