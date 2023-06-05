cmake_minimum_required(VERSION 3.13)

include(pico-sdk/pico_sdk_init.cmake)

project(test)

pico_sdk_init()

add_executable(test
    src/digitalIO.c
    src/ILI9225.c
    src/spi.c
    src/timing.c
    src/main.c
)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(test pico_stdlib hardware_spi)

target_include_directories(test PRIVATE ${CMAKE_SOURCE_DIR}/src)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(test)