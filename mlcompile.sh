#!/bin/bash

# Supply the file as an argument to this script to compile it using mlpack
# without the need for Makefile installed

echo "g++ -I/usr/include/libxml2/ $1 -lmlpack -Wl,-rpath=/usr/local/lib"
g++ -I/usr/include/libxml2/ $1 -lmlpack -Wl,-rpath=/usr/local/lib
