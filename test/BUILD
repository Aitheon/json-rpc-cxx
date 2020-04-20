load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
  name = "jsonrpccxx-test",
  srcs = [
    "integrationtest.hpp",
    "testclientconnector.hpp",
    "testserverconnector.hpp",
    "batchclient.cpp",
    "client.cpp",
    "dispatcher.cpp",
    "main.cpp",
    "server.cpp",
    "typemapper.cpp",
    "warehouseapp.cpp"
  ],
  deps = [
    "//vendor:catch",
    "//include/jsonrpccxx",
    "//include/jsonrpccxx/connectors",
    "//examples/warehouse:libwarehouse"
  ]
)