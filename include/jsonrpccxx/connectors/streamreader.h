#ifndef STREAMREADER_H
#define STREAMREADER_H

#include <string>
#include <memory>

namespace jsonrpccxx {
class StreamReader
{
public:
    StreamReader(size_t buffersize);
    virtual ~StreamReader();

    bool Read(std::string &target, int fd, char delimiter);

private:
    size_t buffersize;
    char* buffer;
};

class NodeIpcStreamReader
{
public:
    NodeIpcStreamReader(StreamReader & reader) : reader(reader) {}
    bool Read(std::string &target, int fd, char delimiter);

private:
    StreamReader & reader;
};
}
#endif // STREAMREADER_H
