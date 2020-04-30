#include "jsonrpccxx/connectors/streamwriter.h"
#include <unistd.h>
#include <sstream>

using namespace jsonrpccxx;
using namespace std;

bool NodeIpcStreamWriter::Write(const string &source, int fd, char delimiter) {
  std::stringstream message;
  message << R"({"type":"data","data":)" << source << '}' << delimiter;
  return this->writer.Write(message.str(), fd);
}

bool StreamWriter::Write(const string &source, int fd) {
  ssize_t bytesWritten;
  size_t totalSize = source.size();
  size_t remainingSize = totalSize;

  do {
    bytesWritten =
        write(fd, source.c_str() + (totalSize - remainingSize), remainingSize);
    if (bytesWritten < 0) {
      return false;
    } else {
      remainingSize -= static_cast<size_t>(bytesWritten);
    }
  } while (remainingSize > 0);
  return true;
}
