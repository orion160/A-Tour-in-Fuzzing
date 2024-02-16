#include <cstdio>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#include <request.hpp>

inline constexpr std::size_t REQUEST_SZ = 512;

int main(int argc, char **argv) {
  ::sockaddr_in serverAddress;
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = ::htons(9000);
  serverAddress.sin_addr.s_addr = INADDR_ANY;

  const auto socket = ::socket(AF_INET, SOCK_STREAM, 0);
  if (socket == -1) {
    ::perror("socket()");
    return -1;
  }

  const auto e_bind =
      ::bind(socket, reinterpret_cast<sockaddr *>(&serverAddress),
             sizeof(serverAddress));
  if (e_bind == -1) {
    std::perror("bind()");
    return -1;
  }

  const auto e_listen = ::listen(socket, SOMAXCONN);
  if (e_listen == -1) {
    std::perror("listen() failed");
    return -1;
  }

  ::sockaddr_in clientAddress{};
  auto clientAddressSize = static_cast<socklen_t>(sizeof(clientAddress));
  uint8_t buffer[REQUEST_SZ];
  while (true) {
    const auto client =
        ::accept(socket, reinterpret_cast<sockaddr *>(&clientAddress),
                 &clientAddressSize);

    if (client == -1) {
      std::perror("accept()");
      return -1;
    }

    const auto e_recv = ::recv(client, buffer, REQUEST_SZ, 0);
    if (e_recv == -1) {
      std::perror("recv()");
      goto e_quit;
    }

    parse_request(buffer);

  e_quit:
    ::close(client);
  }

  ::close(socket);

  return 0;
}
