#include <main.h>

int socket_connect(char *host, in_port_t port) {
  struct hostent *hp;
  struct sockaddr_in addr;
  int on = 1, sock;

  if ((hp = gethostbyname(host)) == NULL) {
    herror("gethostbyname");
    exit(1);
  }
  bcopy(hp->h_addr, &addr.sin_addr, hp->h_length);
  addr.sin_port = htons(port);
  addr.sin_family = AF_INET;
  sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (const char *)&on, sizeof(int));

  if (sock == -1) {
    perror("setsockopt");
    exit(1);
  }

  if (connect(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) ==
      -1) {
    perror("connect");
    exit(1);
  }
  return sock;
}

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int fd;
  char buffer[BUFFER_SIZE];

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(1);
  }
  fd = socket_connect(argv[1], atoi(argv[2]));
  string req = get("/", {{"Host: example.com"}}).c_str();
  write(fd, (const void *)req.c_str(),
        req.length()); // write(fd, char[]*, len);
  bzero(buffer, BUFFER_SIZE);

  while (recv(fd, buffer, BUFFER_SIZE - 1, MSG_DONTWAIT) != 0) {
    // fprintf(stderr, "%s", buffer);
    bzero(buffer, BUFFER_SIZE);
  }

  shutdown(fd, SHUT_RDWR);
  close(fd);

  return 0;
}
