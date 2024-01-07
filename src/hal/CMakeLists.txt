add_library(hal INTERFACE)
target_include_directories(hal INTERFACE ${CMAKE_CURRENT_LIST_DIR})

add_library(adc adc.c adc.h)
