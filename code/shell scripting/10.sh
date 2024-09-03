#!/bin/sh

# Write a script to backup a given directory to a given file_name.tar.gz in your home directory. 
# Both, the directory name and the backup file has to be passed as command line input. 
# Design the script with suitable exception handling.

tar -cvf "$2.tar" $1
gzip "$2.tar" 
mv "$2.tar.gz" ~