# json-rpc-cxx


[![Build status](https://ci.appveyor.com/api/projects/status/c6rv869h984m1eo2?svg=true)](https://ci.appveyor.com/project/cinemast/json-rpc-cxx)
[![CircleCI](https://circleci.com/gh/jsonrpcx/json-rpc-cxx.svg?style=svg)](https://circleci.com/gh/jsonrpcx/json-rpc-cxx)
![GitHub](https://img.shields.io/github/license/jsonrpcx/json-rpc-cxx.svg)
[![codecov](https://codecov.io/gh/jsonrpcx/json-rpc-cxx/branch/master/graph/badge.svg)](https://codecov.io/gh/jsonrpcx/json-rpc-cxx)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/jsonrpcx/json-rpc-cxx.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/jsonrpcx/json-rpc-cxx/context:cpp)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/16b095ad49964288b524bc0b499c4efb)](https://www.codacy.com/app/cinemast/json-rpc-cxx?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=jsonrpcx/json-rpc-cxx&amp;utm_campaign=Badge_Grade)
![GitHub tag (latest SemVer)](https://img.shields.io/github/tag/jsonrpcx/json-rpc-cxx.svg)

![json-rpc-cxx-icon](doc/icon.png)

A [JSON-RPC](https://www.jsonrpc.org/) (1.0 & 2.0) framework implemented in C++17 using the [nlohmann's json for modern C++](https://github.com/nlohmann/json).

-   JSON-RPC 1.0 and 2.0 compliant client
-   JSON-RCP 1.0 and 2.0 compliant server
-   Transport agnostic interfaces
-   Compile time type mapping (using [nlohmann's arbitrary type conversion](https://github.com/nlohmann/json#arbitrary-types-conversions))
-   Runtime type checking
-   Cross-platform (Windows, Linux, OSX)

## Build with Cmake

-   Copy [include/jsonrpccxx](include) to your include path
-   Alternatively use CMake install mechanism

```bash
mkdir build && cd build
cmake ..
sudo make install
```

## Build with Bazel

### Installing Bazelisk as Bazel

It is recommended to use [Bazelisk](https://github.com/bazelbuild/bazelisk) installed as `bazel`, to avoid Bazel compatibility issues.
On Linux, run the following commands:

```
sudo wget -O /usr/local/bin/bazel https://github.com/bazelbuild/bazelisk/releases/download/v1.3.0/bazelisk-linux-amd64
sudo chmod +x /usr/local/bin/bazel
```

On macOS, run the follwing command:
```
brew install bazelbuild/tap/bazelisk
```

If you're a fan of Node.js, install your Bazelisk via
```
npm install -g @bazel/bazelisk
```

To install the Go version, type:
```
go get github.com/bazelbuild/bazelisk
```
To add it to your PATH:
```
export PATH=$PATH:$(go env GOPATH)/bin
```

### Installing Bazel standalone
To install `bazel` on your own, follow the [Bazel installation](https://docs.bazel.build/versions/master/install.html)


### Bazel build commands

Build all

```
bazel build ...
```

Build warehouse example

```
bazel build //examples:warehouse
```

## Usage

-   [examples/warehouse/main.cpp](examples/warehouse/main.cpp)

## Design goals

-   Easy to use interface
-   Type safety where possible
-   Avoid errors at compile time where possible
-   Test driven development
-   Choose expressiveness over speed
-   Minimal dependencies

## License

This framework is licensed under [MIT](LICENSE).

### Dependencies

-   [nlohmann's JSON for modern C++](https://github.com/nlohmann/json) is licensed under MIT.
-   Optional: [Catch](https://github.com/catchorg/Catch2) is licensed under BSL-1.0.

## Developer information

-   [CONTRIBUTING.md](CONTRIBUTING.md)
-   [CHANGELOG.md](CHANGELOG.md)
