#!/bin/bash

# Supply the file as an argument to this script to compile it using mlpack
# without the need for Makefile installed
# output is [filename].out

echo "g++ --std=c++11 -I/usr/include/libxml2/ $1 -o ${1/.cpp/.out} -lmlpack -Wl,-rpath=/usr/local/lib"
g++ --std=c++11 -I/usr/include/libxml2/ $1 -o ${1/.cpp/.out} -lmlpack -Wl,-rpath=/usr/local/lib
