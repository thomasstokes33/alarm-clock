cmake_minimum_required(VERSION 3.13)


include(../pico-sdk/pico_sdk_init.cmake)

set(PROJECT_NAME time)

project(${PROJECT_NAME})
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

pico_sdk_init()

add_executable(${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR} )
target_link_libraries(${PROJECT_NAME} 
	pico_cyw43_arch_lwip_threadsafe_background 
	pico_stdlib 
	hardware_adc
	hardware_pwm 
	hardware_clocks
)

target_sources(${PROJECT_NAME}
	PRIVATE picow_ntp_client.c 
)

pico_add_extra_outputs(${PROJECT_NAME})

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 1)
pico_add_extra_outputs(${PROJECT_NAME})
