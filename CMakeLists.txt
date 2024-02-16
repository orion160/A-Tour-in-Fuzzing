cmake_minimum_required(VERSION 3.27)
project("A Tour into Fuzzing" LANGUAGES CXX)

add_library(base INTERFACE)
set_target_properties(base PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

set(ENABLE_FUZZING "OFF" CACHE STRING  "Enable fuzzing. Possible values are [libFuzzing]")

add_subdirectory(server)

if(NOT ${ENABLE_FUZZING} STREQUAL "OFF")
    add_subdirectory(fuzzing)
endif()
