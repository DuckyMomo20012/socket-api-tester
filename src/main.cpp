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
#define PORT 80

int main(int argc, char *argv[]) {
  int fd;
  char buffer[BUFFER_SIZE];
  string web{argv[1]};
  string outFile{argv[2]};

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <http website> <output file>\n", argv[0]);
    exit(1);
  }
  if (web.find("https") != web.npos) {
    cerr << "Please input a http website" << endl;
    exit(1);
  }
  fd = socket_connect(argv[1], PORT);
  string req = get("/", {{"Host: example.com"}});
  write(fd, (const void *)req.c_str(),
        req.length()); // write(fd, char[]*, len);
  bzero(buffer, BUFFER_SIZE);

  while (read(fd, buffer, BUFFER_SIZE - 1) > 0) {
    string buff(buffer);
    string endHeader = "\r\n\r\n";
    int pos = buff.find(endHeader);
    if (pos > 0) {
      string sub = buff.substr(pos + endHeader.length(), buff.length());
      cout << sub;
      writeFile(outFile, sub, ios::trunc);
    } else {
      cout << buff;
      writeFile(outFile, buff, ios::app);
    }
    // fprintf(stderr, "%s", buffer);
    bzero(buffer, BUFFER_SIZE);
  }

  shutdown(fd, SHUT_RDWR);
  close(fd);
  return 0;
}
