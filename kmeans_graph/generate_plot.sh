#!/bin/bash

# $1 - cluster amount
# $2 - input file

EXEC_FILE="./kmeans.out"

if (( ${#@} > 1 )); then
     $EXEC_FILE $1 $2
elif (( ${#@} > 0 )); then
    $EXEC_FILE $1 
else
    $EXEC_FILE
fi

gnuplot plot.gp
