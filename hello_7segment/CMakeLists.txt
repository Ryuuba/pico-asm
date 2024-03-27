add_executable(hello_7segment
        hello_7segment.c
        )

# pull in common dependencies
target_link_libraries(hello_7segment pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(hello_7segment)
