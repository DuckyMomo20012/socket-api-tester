#include "main.h"

int socket_connect(char *host, in_port_t port) {
  struct hostent *hp;
  struct sockaddr_in addr;
  int sock;
  struct timeval timeout;
  double timeout_sec = 3.0;

  if ((hp = gethostbyname(host)) == NULL) {
    herror("gethostbyname");
    exit(1);
  }
  bcopy(hp->h_addr, &addr.sin_addr, hp->h_length);
  addr.sin_port = htons(port);
  addr.sin_family = AF_INET;
  sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

  timeout.tv_sec = timeout_sec;
  timeout.tv_usec = 0;
  setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char *)&timeout,
             sizeof(timeout));

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
#define PORT 80 // http use port 80

int main(int argc, char *argv[]) {
  int fd;
  char buffer[BUFFER_SIZE];
  string web{argv[1]};
  string outFile{argv[2]};
  string headerFile = "log/header.txt";
  string requestFile = "log/request.txt";

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <http website> <output file>\n", argv[0]);
    exit(1);
  }
  if (outFile.find(".txt") == outFile.npos) {
    cout << "WARNING: You should write data to text file (.txt) instead of "
         << "\"" << outFile << "\"" << endl;
  }
  if (web.find("http://") == web.npos) {
    cerr << "Please input a http website" << endl;
    exit(1);
  }

  string host;
  string uri = "/";
  int HTTP_LEN = 7; // Length of "http://"

  size_t slashPos = web.find("/", HTTP_LEN);

  if (slashPos == web.npos) {
    host = web.substr(HTTP_LEN);
  } else {
    host = web.substr(HTTP_LEN, slashPos - HTTP_LEN);
    uri = web.substr(slashPos);
  }

  // Because socket connect using host, so we have to extract it from website,
  // which is inputed from command.
  fd = socket_connect(const_cast<char *>(host.c_str()), PORT);
  string req = get(uri, {{"Host", host}, {"Connection: Keep-alive"}});
  writeFile(requestFile, req, ios::app);

  write(fd, (const void *)req.c_str(),
        req.length()); // write(fd, char[]*, len);
  bzero(buffer, BUFFER_SIZE);

  // Always truncate file first
  writeFile(outFile, "", ios::trunc);
  writeFile(headerFile, "", ios::trunc);
  cout << "Writing data to: " << outFile << endl;
  // Sometimes header is too big for buffer, so we can't find "\r\n\r\n". When
  // we found it, we mark as the file is opened and write data to file, discard
  // those headers.
  bool isFileOpened = false;
  while (read(fd, buffer, BUFFER_SIZE - 1) > 0) {
    string buff(buffer);
    string endHeader = "\r\n\r\n";
    // TODO: Optimize header detection
    int pos = buff.find(endHeader);

    if (pos > 0) {
      isFileOpened = true;
      string header = buff.substr(0, pos + endHeader.length());
      string sub = buff.substr(pos + endHeader.length(), buff.length());

      writeFile(outFile, sub, ios::app);
      // If header is equal buff, that means at the end of buff can have
      // \r\n\r\n, leads to data is not written to outFile.
      // REVIEW: This could be a bug too
      if (header == buff and buff.find("Content-Length: 0") == buff.npos) {
        writeFile(outFile, buff, ios::app);
      } else {
        // Some buffers will have \r\n\r\n at the end
        // If header == buff then it might be a 301 response with empty data.
        writeFile(headerFile, header, ios::app);
      }
    } else if (isFileOpened) {
      writeFile(outFile, buff, ios::app);
    } else {
      writeFile(headerFile, buff, ios::app);
    }
    bzero(buffer, BUFFER_SIZE);
  }

  shutdown(fd, SHUT_RDWR);
  close(fd);
  return 0;
}
