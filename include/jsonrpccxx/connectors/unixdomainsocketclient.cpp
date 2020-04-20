/*************************************************************************
 * libjson-rpc-cpp
 *************************************************************************
 * @file    unixdomainsocketclient.cpp
 * @date    11.05.2015
 * @author  Alexandre Poirot <alexandre.poirot@legrand.fr>
 * @license See attached LICENSE.txt
 ************************************************************************/

#include "jsonrpccxx/connectors/unixdomainsocketclient.h"
#include "jsonrpccxx/connectors/sharedconstants.h"
#include "jsonrpccxx/connectors/streamreader.h"
#include "jsonrpccxx/connectors/streamwriter.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

using namespace jsonrpccxx;
using namespace std;

UnixDomainSocketClient::UnixDomainSocketClient(const std::string &path)
    : path(path) {}

UnixDomainSocketClient::~UnixDomainSocketClient() {}

std::string UnixDomainSocketClient::Send(const std::string &request) {
  sockaddr_un address;
  int socket_fd;
  socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
  if (socket_fd < 0) {
    throw JsonRpcException(-32003, "Could not create unix domain socket");
  }
  memset(&address, 0, sizeof(sockaddr_un));

  address.sun_family = AF_UNIX;
  strncpy(address.sun_path, this->path.c_str(), 107);

  if (connect(socket_fd, (struct sockaddr *)&address, sizeof(sockaddr_un)) !=
      0) {
    throw JsonRpcException(-32003, "Could not connect to: " + this->path);
  }

  StreamWriter writer;
  string toSend = request + DEFAULT_DELIMITER_CHAR;
  if (!writer.Write(toSend, socket_fd)) {
    throw JsonRpcException(-32003, "Could not write request");
  }

  std::string result;
  StreamReader reader(DEFAULT_BUFFER_SIZE);
  if (!reader.Read(result, socket_fd, DEFAULT_DELIMITER_CHAR)) {
    throw JsonRpcException(-32003, "Could not read response");
  }
  close(socket_fd);
  return result;
}
