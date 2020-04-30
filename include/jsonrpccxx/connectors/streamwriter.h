#ifndef STREAMWRITER_H
#define STREAMWRITER_H

#include <string>
#include <memory>

namespace jsonrpccxx {

class StreamWriter
{
public:
    bool Write(const std::string &source, int fd);
};

class NodeIpcStreamWriter
{
public:
    NodeIpcStreamWriter(StreamWriter & writer) : writer(writer) {}
    bool Write(const std::string &source, int fd, char delimiter);

private:
    StreamWriter & writer;
};

}


#endif // STREAMWRITER_H
