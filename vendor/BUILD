load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
  name = "catch",
  hdrs = ["catch/catch.hpp"],
  # for dependent outputs use: copts = ["-Ivendor"] or in this one: includes = ["../vendor"]
  visibility = ["//visibility:public"]
)

cc_library(
  name = "nlohmann",
  hdrs = glob(["nlohmann/**/*.hpp"]),
  # for dependent outputs use: copts = ["-Ivendor"] or in this one: includes = ["../vendor"]
  visibility = ["//visibility:public"]
)

cc_library(
  name = "cpp-httplib",
  hdrs = ["cpp-httplib/httplib.h"],
  # for dependent outputs use: copts = ["-Ivendor"] or in this one: includes = ["../vendor"]
  visibility = ["//visibility:public"]
)