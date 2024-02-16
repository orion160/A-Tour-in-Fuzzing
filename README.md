# A Tour into Fuzzing

## Fuzzing

### parse_request

```cpp
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
```

To test a payload use

```bash
cat <payload> | nc localhost 9000
# or
echo <payload> -ne | nc localhost 9000
```

Use `xxd` for getting encode/decode the payload

### Tools

#### libFuzzer

Set `ENABLE_FUZZING=libFuzzer` or use `x64-linux-libFuzzer` preset.
