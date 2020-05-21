load("@rules_cc//cc:defs.bzl", "cc_library", "cc_binary")

cc_library(
  name = "libwarehouse",
  hdrs = [
    "types.h",
    "warehouseapp.hpp"
  ],
  srcs = [
    "warehouseapp.cpp"
  ],
  visibility = [
    "//test:__pkg__"
  ],
  deps = [
    "@github_nlohmann_json//:json",
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