#ifndef _MAIN_H_
#define _MAIN_H_
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "helpers.h"
#include "request.h"
#include <fstream>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sstream>
#include <sys/socket.h>
#include <sys/types.h>
using namespace std;

int socket_connect(char *host, in_port_t port);
int main(int argc, char *argv[]);

#endif
