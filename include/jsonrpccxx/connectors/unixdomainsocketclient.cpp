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

void UnixDomainSocketClient::Connect() {
  sockaddr_un address;
  socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
  if (socket_fd < 0) {
    throw JsonRpcException(-32003, "Could not create unix domain socket");
  }
  memset(&address, 0, sizeof(sockaddr_un));

  address.sun_family = AF_UNIX;
  strncpy(address.sun_path, this->path.c_str(), 107);

  auto res = connect(socket_fd, (struct sockaddr *)&address, sizeof(sockaddr_un));
  if (res != 0) {
    throw JsonRpcException(-32003, "Could not connect to: " + this->path);
  }
}

void UnixDomainSocketClient::Disconnect() {

}

std::string UnixDomainSocketClient::Send(const std::string &request) {

  StreamWriter writer;
  NodeIpcStreamWriter ipcWriter(writer);
  string toSend = request;
  if (!ipcWriter.Write(toSend, socket_fd, DEFAULT_DELIMITER_CHAR)) {
    throw JsonRpcException(-32003, "Could not write request");
  }

  std::string result;
  StreamReader reader(DEFAULT_BUFFER_SIZE);
  NodeIpcStreamReader nodeIpcReader(reader);
  if (!nodeIpcReader.Read(result, socket_fd, DEFAULT_DELIMITER_CHAR)) {
    throw JsonRpcException(-32003, "Could not read response");
  }
  return result;
}

void UnixDomainSocketClient::Notify(const std::string &request) {
  StreamWriter writer;
  NodeIpcStreamWriter ipcWriter(writer);
  string toSend = request;
  if (!ipcWriter.Write(toSend, socket_fd, DEFAULT_DELIMITER_CHAR)) {
    throw JsonRpcException(-32003, "Could not write request");
  }
}

void UnixDomainSocketClient::Close() {
  close(socket_fd);
}
