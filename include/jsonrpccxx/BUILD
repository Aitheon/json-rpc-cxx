load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
  name = "jsonrpccxx",
  hdrs = glob(["*.hpp"]),
  include_prefix = "jsonrpccxx",
  visibility = ["//visibility:public"],
  deps = [
    "//vendor:catch",
    "//vendor:nlohmann"
  ]
)