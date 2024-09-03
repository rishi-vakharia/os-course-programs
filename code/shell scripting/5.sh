#!/bin/sh

# Use 'find' command to look for a file and echo a suitable message if the file is not found. 

path=$(find ~ -name $1)  # Don't put a space around = in shell script

flag=$(echo $path | wc -w)

if [ $flag -eq 0 ] 
then 
    echo "$1 not found in /home directory"
else 
    echo "$1 found at $path"
fi