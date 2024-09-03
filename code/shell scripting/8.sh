#!/bin/sh

# Write shell script that takes a login name as command–line argument 
# and reports when that person logged in.

if [ $# -ne 0 ]
then
    if [ $(last $1 | head -n 1 | wc -w) -ne 0 ]
    then
        echo "$1: logged in on $(last $1 | head -n 1 | cut -c 40-55) hours"
    else
        echo "$1: user doesn't exist"
    fi
fi