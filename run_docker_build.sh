#!/bin/sh

set -xe

cd /tmp
mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX=~/.local -DCMAKE_CXX_FLAGS="-Wall -Wextra" /io
make install
make tests
ctest --output-on-failure --timeout 100 ${MAKEFLAGS}
