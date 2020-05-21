load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
  name = "connectors",
  hdrs = glob(["*.hpp", "*.h"]),
  srcs = glob(["*.cpp"]),
  include_prefix = "jsonrpccxx/connectors",
  visibility = ["//visibility:public"],
  deps = [
    "//third_party:cpp-httplib",
    "//include/jsonrpccxx"
  ]
)