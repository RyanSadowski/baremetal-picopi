# Generated Cmake Pico project file
cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/home/namo/Packages/pico-sdk")
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.4.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.4.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

project(blinkyboi C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1
add_executable(blinkyboi blinkyboi.c)

pico_set_program_name(blinkyboi "blinkyboi")
pico_set_program_version(blinkyboi "0.1")

# Add the standard library to the build
target_link_libraries(blinkyboi
        hardware_resets 
        hardware_irq
        pico_stdlib)

# Send data over usb
pico_enable_stdio_usb(blinkyboi 1)
pico_enable_stdio_uart(blinkyboi 0)

# Add the standard include files to the build
target_include_directories(blinkyboi PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
)

pico_add_extra_outputs(blinkyboi)
