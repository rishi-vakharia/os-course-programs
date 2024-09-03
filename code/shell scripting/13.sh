#!/bin/sh

# Print multiplication table of cmd line arg.

for i in $(seq 1 10)
do
    echo "$1 x $i = $(($1*i))"
done 