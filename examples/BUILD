load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
  name = "connectors",
  hdrs = [
    "inmemoryconnector.hpp",
    "cpphttplibconnector.hpp"
  ],
  visibility = ["//visibility:public"],
  deps = [
    "//vendor:cpp-httplib",
    "//include/jsonrpccxx"
  ]
)