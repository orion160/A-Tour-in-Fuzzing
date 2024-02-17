cmake_minimum_required(VERSION 3.27)
project("A Tour into Fuzzing" LANGUAGES CXX)

add_library(base_TIF INTERFACE)
set_target_properties(base_TIF PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

set(FUZZING_OPTIONS libFuzzing fuzztest fuzztest-unit)
string(JOIN ", " FUZZING_OPTIONS_STR ${FUZZING_OPTIONS})
set(ENABLE_FUZZING "OFF" CACHE STRING  "Enable fuzzing. Possible values are [${FUZZING_OPTIONS_STR}]")

# deps
if (${ENABLE_FUZZING} STREQUAL "fuzztest")
    add_subdirectory(fuzztest)
    enable_testing()
endif()

# TIF
add_subdirectory(server)

if(NOT ${ENABLE_FUZZING} STREQUAL "OFF")
    if (${ENABLE_FUZZING} IN_LIST FUZZING_OPTIONS)
        add_subdirectory(fuzzing)
    endif()
endif()
