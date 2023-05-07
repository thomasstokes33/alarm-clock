cmake_minimum_required(VERSION 3.13)


include(../pico-sdk/pico_sdk_init.cmake) ######todo: path to pico-sdk

set(PROJECT_NAME time)

project(${PROJECT_NAME})
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

pico_sdk_init()

add_executable(${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR} ) #includes the location of this file as directory to search for headers 
target_link_libraries(${PROJECT_NAME} 
	pico_cyw43_arch_lwip_threadsafe_background 
	pico_stdlib 
	hardware_adc
	hardware_pwm 
	hardware_clocks
)

target_sources(${PROJECT_NAME}
	PRIVATE ##todo: add source files
)

message(PROJECT_BINARY_DIR="${PROJECT_BINARY_DIR}") # how to output messages during cmake process
message(Current list dir="${CMAKE_CURRENT_LIST_DIR} ")

pico_add_extra_outputs(${PROJECT_NAME})

pico_enable_stdio_usb(${PROJECT_NAME} 1) #ensures we can communicate over usb
pico_enable_stdio_uart(${PROJECT_NAME} 1)
pico_add_extra_outputs(${PROJECT_NAME})
