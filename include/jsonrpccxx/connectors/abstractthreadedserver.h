#ifndef ABSTRACTTHREADEDSERVER_H
#define ABSTRACTTHREADEDSERVER_H

#include "threadpool.h"
#include "jsonrpccxx/iserverconnector.hpp"
#include "jsonrpccxx/iserverlistener.hpp"
#include <memory>
#include <thread>

namespace jsonrpccxx {

  class AbstractThreadedServer : public IServerListener {
  public:
    AbstractThreadedServer(IServerConnector &serverConnector, size_t threads);
    virtual ~AbstractThreadedServer();

    virtual bool StartListening();
    virtual bool StopListening();

  protected:
    IServerConnector &getServerConnector() const { return this->serverConnector; }

    /**
     * @brief InitializeListener should initialize sockets, file descriptors etc.
     * @return
     */
    virtual bool InitializeListener() = 0;

    /**
     * @brief CheckForConnection should poll for a new connection. This must be
     * a non-blocking call.
     * @return a handle which is passed on to HandleConnection()
     */
    virtual int CheckForConnection() = 0;

    /**
     * @brief HandleConnection must handle connection information for a given
     * handle that has been returned by CheckForConnection()
     * @param connection
     */
    virtual void HandleConnection(int connection) = 0;

  private:
    IServerConnector &serverConnector;
    bool running;
    ThreadPool threadPool;
    size_t threads;
    std::unique_ptr<std::thread> listenerThread;

    void ListenLoop();
  };
} // namespace jsonrpccxx

#endif // ABSTRACTTHREADEDSERVER_H
