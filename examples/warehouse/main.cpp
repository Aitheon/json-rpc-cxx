#include "jsonrpccxx/connectors/inmemoryconnector.hpp"
#include "jsonrpccxx/connectors/cpphttplibconnector.hpp"
#include "jsonrpccxx/connectors/unixdomainsocketclient.h"
#include "jsonrpccxx/connectors/unixdomainsocketserver.h"
#include "warehouseapp.hpp"

#include <iostream>
#include <jsonrpccxx/client.hpp>
#include <jsonrpccxx/server.hpp>

using namespace jsonrpccxx;
using namespace std;

class WareHouseClient {
public:
  explicit WareHouseClient(JsonRpcClient &client) : client(client) {}
  bool AddProduct(const Product &p) { return client.CallMethod<bool>(1, "AddProduct", {p}); }
  Product GetProduct(const std::string &id) { return client.CallMethod<Product>(1, "GetProduct", {id}); }

private:
  JsonRpcClient &client;
};

void doWarehouseStuff(IClientConnector &clientConnector) {
  JsonRpcClient client(clientConnector, version::v2);
  WareHouseClient appClient(client);
  Product p = {"0xff", 22.4, "Product 1", category::cash_carry};
  cout << "Adding product: " << std::boolalpha << appClient.AddProduct(p) << "\n";

  Product p2 = appClient.GetProduct("0xff");
  cout << "Found product: " << p2.name << "\n";
  try {
    appClient.GetProduct("0xff2");
  } catch (JsonRpcException &e) {
    cerr << "Error finding product: " << e.what() << "\n";
  }
}

int main() {
  JsonRpc2Server rpcServer;

  // Bindings
  WarehouseServer app;
  rpcServer.Add("GetProduct", GetHandle(&WarehouseServer::GetProduct, app), {"id"});
  rpcServer.Add("AddProduct", GetHandle(&WarehouseServer::AddProduct, app), {"product"});

  cout << "Running in-memory example" << "\n";
  InMemoryConnector inMemoryConnector(rpcServer);
  doWarehouseStuff(inMemoryConnector);

  cout << "Running http example" << "\n";
  CppHttpLibServerConnector httpServer(rpcServer, 8484);
  cout << "Starting http server: " << std::boolalpha << httpServer.StartListening() << "\n";
  CppHttpLibClientConnector httpClient("localhost", 8484);
  std::this_thread::sleep_for(0.5s);
  doWarehouseStuff(httpClient);

  cout << "Running unix-socket example" << "\n";
  jsonrpccxx::UnixDomainSocketServer unixSocketsServer(rpcServer, "./cpp-node");
  cout << "Starting unix-socket server: " << std::boolalpha << unixSocketsServer.StartListening() << "\n";
  jsonrpccxx::UnixDomainSocketClient unixSocketsClient("./cpp-node");
  std::this_thread::sleep_for(0.5s);
  doWarehouseStuff(unixSocketsClient);

  return 0;
}