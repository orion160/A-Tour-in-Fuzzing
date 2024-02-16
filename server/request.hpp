#pragma once

#include <cstdint>

enum class request_type : uint8_t;

struct request_header;

void parse_message(request_header *h, const uint8_t *data);

void parse_request(const uint8_t *raw);
