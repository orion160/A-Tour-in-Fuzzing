#include <cstdint>

#include <request.hpp>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, std::size_t Size) {
  parse_request(Data);
  return 0;
}
