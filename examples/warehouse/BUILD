load("@rules_cc//cc:defs.bzl", "cc_library", "cc_binary")

cc_library(
  name = "libwarehouse",
  srcs = [
    "types.h",
    "warehouseapp.hpp",
    "warehouseapp.cpp",
  ],
  visibility = [
    "//test:__pkg__"
  ],
  deps = [
    "//vendor:nlohmann",
    "//include/jsonrpccxx"
  ]
)

cc_binary(
  name = "warehouse",
  srcs = [
    "main.cpp"
  ],
  linkopts = ["-lpthread"],
  deps = [
    "//include/jsonrpccxx",
    "//include/jsonrpccxx/connectors",
    ":libwarehouse"
  ]
)