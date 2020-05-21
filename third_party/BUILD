load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
  name = "catch",
  hdrs = ["catch/catch.hpp"],
  # for dependent outputs use: copts = ["-Ithird_party"] or in this one: includes = ["../third_party"]
  includes = ["../third_party"],
  visibility = ["//visibility:public"]
)

cc_library(
  name = "cpp-httplib",
  hdrs = ["cpp-httplib/httplib.h"],
  # for dependent outputs use: copts = ["-Ithird_party"] or in this one: includes = ["../third_party"]
  includes = ["../third_party"],
  visibility = ["//visibility:public"]
)