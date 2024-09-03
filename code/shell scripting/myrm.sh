#!/bin/sh

# Implement a safe 'rm' command called 'myrm.sh' that sends files to Recycle bin instead of deleting.


if [ ! -d ~/RecycleBin ]   # if directory not exists     
then
    mkdir ~/RecycleBin
fi

for var in $@
do 
    if [ -f $var ]
    then
        mv $var ~/RecycleBin
        echo "$var moved to RecycleBin"
    else 
        echo "$var: no such file exists"
    fi
done