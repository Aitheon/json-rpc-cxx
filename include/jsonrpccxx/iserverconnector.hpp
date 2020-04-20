#pragma once
#include <string>

namespace jsonrpccxx {

  class IServerConnector {
  public:
    virtual std::string HandleRequest(const std::string &request) = 0;
    virtual ~IServerConnector() = default;
  };

} // namespace jsonrpccxx