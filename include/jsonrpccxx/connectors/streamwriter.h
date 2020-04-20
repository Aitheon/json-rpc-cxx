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

}


#endif // STREAMWRITER_H
