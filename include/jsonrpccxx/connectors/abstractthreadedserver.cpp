#include "jsonrpccxx/connectors/abstractthreadedserver.h"

using namespace jsonrpccxx;
using namespace std;

AbstractThreadedServer::AbstractThreadedServer(IServerConnector & serverConnector, size_t threads)
    : serverConnector(serverConnector), running(false), threadPool(threads), threads(threads) {}

AbstractThreadedServer::~AbstractThreadedServer() { this->StopListening(); }

bool AbstractThreadedServer::StartListening() {
  if (this->running)
    return false;

  if (!this->InitializeListener())
    return false;

  this->running = true;

  this->listenerThread =
      unique_ptr<thread>(new thread(&AbstractThreadedServer::ListenLoop, this));

  return true;
}

bool AbstractThreadedServer::StopListening() {
  if (!this->running)
    return false;

  this->running = false;

  this->listenerThread->join();
  return true;
}

void AbstractThreadedServer::ListenLoop() {
  while (this->running) {
    int conn = this->CheckForConnection();

    if (conn > 0) {
      this->AddConnection(conn);
      if (this->threads > 0) {
        this->threadPool.enqueue(&AbstractThreadedServer::HandleConnection,
                                 this, conn);
      } else {
        this->HandleConnection(conn);
      }
    } else {
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
  }
}
