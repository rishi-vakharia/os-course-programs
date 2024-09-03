#!/bin/sh

# Echo error message if num of cmd line arguments != 3
# O/w print the cmd line args

if [ $# -eq 3 ]
then
    echo "$@: The cmd-line args entered"
else 
    echo "Error: No. of cmd-line args != 3"
fi