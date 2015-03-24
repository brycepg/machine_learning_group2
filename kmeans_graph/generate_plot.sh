#!/bin/bash

# $1 - cluster amount
# $2 - input file

EXEC_FILE="./kmeans.out"

if [ ! -e kmeans.out ]; then
    ../mlcompile.sh kmeans.cpp
fi

if (( ${#@} > 1 )); then
     $EXEC_FILE $1 $2
elif (( ${#@} > 0 )); then
    $EXEC_FILE $1 
else
    $EXEC_FILE 10
fi

gnuplot plot.gp
