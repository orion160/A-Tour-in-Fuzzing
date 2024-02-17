#include <cstdint>

#include <fuzztest/fuzztest.h>

#include <request.hpp>

// Unit test with empty input can be added - aka nullptr

void ParseRequestFuzz(const std::vector<uint8_t> &input) {
  parse_request(input.data());
}
FUZZ_TEST(Requests, ParseRequestFuzz)
    .WithDomains(
        fuzztest::NonEmpty(fuzztest::Arbitrary<std::vector<uint8_t>>()));
