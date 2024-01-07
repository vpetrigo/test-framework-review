cmake_minimum_required(VERSION 3.17)
project(simple-app C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(../cmake/cpputest_helper.cmake)

option(ENABLE_TESTING "Enable unit-testing" OFF)

if (ENABLE_TESTING)
    enable_testing()
endif ()

# CppUTest
include(FetchContent)
FetchContent_Declare(
        CppUTest
        GIT_REPOSITORY https://github.com/cpputest/cpputest.git
        GIT_TAG v4.0 # or use release tag, eg. v4.0
)
# Set this to ON if you want to have the CppUTests in your project as well.
set(TESTS OFF CACHE BOOL "Switch off CppUTest Test build")
FetchContent_MakeAvailable(CppUTest)

find_package(CppUTest REQUIRED)

add_subdirectory(hal/)
add_subdirectory(sensors/)
add_subdirectory(app/)
