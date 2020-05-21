load("@rules_cc//cc:defs.bzl", "cc_library")
 
licenses(["notice"])  # 3-Clause BSD

exports_files(["LICENSE.MIT"])

cc_library(
    name = "json",
    hdrs = glob([
        "include/**/*.hpp",
    ]),
    includes = ["include"],
    visibility = ["//visibility:public"],
    alwayslink = 1,
)