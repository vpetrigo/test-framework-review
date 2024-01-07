add_library(sensors INTERFACE)
target_include_directories(sensors INTERFACE ${CMAKE_CURRENT_LIST_DIR})

add_library(temperature temperature.c temperature.h)
target_link_libraries(temperature PRIVATE adc hal)

cpputest_register_test(temperature hal temperature)
cpputest_add_wrappers(temperature adc_read)
