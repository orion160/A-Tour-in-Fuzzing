add_executable(parse_request_fuzz)
target_sources(parse_request_fuzz PRIVATE parse_request_fuzz.cpp)
target_link_libraries(parse_request_fuzz
    PRIVATE fuzztest::fuzztest fuzztest::fuzztest_gtest_main request
)
