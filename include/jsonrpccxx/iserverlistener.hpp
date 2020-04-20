#pragma once
#include <string>

namespace jsonrpccxx {

  class IServerListener {
  public:
    /**
     * This method should signal the Connector to start waiting for requests, in
     * any way that is appropriate for the derived connector class.
     * If something went wrong, this method should return false, otherwise true.
     */
    virtual bool StartListening() = 0;
    /**
     * This method should signal the Connector to stop waiting for requests, in
     * any way that is appropriate for the derived connector class.
     * If something went wrong, this method should return false, otherwise true.
     */
    virtual bool StopListening() = 0;

    virtual ~IServerListener() = default;
  };
} // namespace jsonrpccxx