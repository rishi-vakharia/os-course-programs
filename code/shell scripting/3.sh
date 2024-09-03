#!/bin/sh

# Implement a 'newfiles.sh' command that creates a new file for each command line argument.

for var in $@
do
    if [ -f $var ]      #https://linuxize.com/post/bash-check-if-file-exists/
    then
        echo "$var already present"
    else
        touch $var
        echo "$var has been created"
    fi
done