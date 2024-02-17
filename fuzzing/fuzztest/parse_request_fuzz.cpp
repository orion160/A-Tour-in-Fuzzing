#include <cstdint>

#include <fuzztest/fuzztest.h>

#include <request.hpp>

void ParseRequestFuzz(const uint8_t *raw) {
  parse_request(raw);
}
FUZZ_TEST(Requests, ParseRequestFuzz);
