cmake_minimum_required(VERSION 3.15)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_BOARD pico_w)
project(pico_asm C CXX ASM)

# Initialize the SDK
pico_sdk_init()

# Add blink example
add_subdirectory(blink)
add_subdirectory(Fibonacci)
add_subdirectory(hello_7segment)
add_subdirectory(rotary_led)