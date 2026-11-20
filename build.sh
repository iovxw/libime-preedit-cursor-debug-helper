#!/bin/sh

PREFIX="${PREFIX:-/usr}" # path to fcitx5 installed prefix
SRC_DIR="${SRC_DIR:-$PWD}" # path to libime source dir
BUILD_DIR="${BUILD_DIR:-$PWD/build}" # path to libime cmake build dir

c++ -std=c++20 -O0 -g \
       -I"$SRC_DIR" \
       -I"$BUILD_DIR/src" \
       -I"$PREFIX/include/Fcitx5/Utils" \
       dump.cpp dump_access.cpp -o dump \
       -L"$BUILD_DIR/bin" \
       -Wl,-rpath,"$BUILD_DIR/bin":"$PREFIX/lib" \
       -lIMEPinyin -lIMECore -lFcitx5Utils -ldl
