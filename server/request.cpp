#include "request.hpp"

#include <cstdio>
#include <cstring>

enum class request_type : uint8_t { HELLO = 0, GOODBYE = 1, MESSAGE = 2 };

struct request_header {
  uint16_t magic;
  request_type type;
  uint16_t length;
};

void parse_message(const request_header *h, const uint8_t *data) {
  uint8_t msg[64];

  // On release this is no-op

  // Critical section
  // Remove conditional for unchecked bounds on memcpy
  // Discoverable via fuzzing
  // if (h->length < 64) {
  std::memcpy(msg, data, h->length);
  // }
}

void parse_request(const uint8_t *raw) {
  auto h = reinterpret_cast<const request_header *>(raw);
  if (h->magic != 0x4545) {
    std::printf("Invalid magic number\n");
    return;
  }

  auto *data = raw + sizeof(request_header);

  switch (h->type) {
  case request_type::HELLO:
    std::printf("HELLO\n");
    break;
  case request_type::GOODBYE:
    std::printf("GOODBYE\n");
    break;
  case request_type::MESSAGE:
    std::printf("MESSAGE: ");
    parse_message(h, data);
    break;
  default:
    std::printf("Unknown request type\n");
    break;
  }
}
