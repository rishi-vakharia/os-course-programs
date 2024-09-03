#!/bin/sh

# Write a shell script to print, “Good Morning/Afternoon/Evening based on the current system time.

hour="$(date +%H)"
if [ $hour -gt 6 -a $hour -le 12 ]
then
    echo "Good Morning"
elif [ $hour -gt 12 -a $hour -le 16 ]
then 
	echo "Good Afternoon"
else
	echo "Good Evening"
fi
