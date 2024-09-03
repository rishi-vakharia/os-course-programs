#!/bin/sh

# Write a shell script that accepts a file name's starting and ending line numbers 
# as arguments and displays all the lines between the given line numbers. 

echo "Enter filename"
read filename
echo ""
echo "Enter starting line number"
read start
echo ""
echo "Enter ending line number"
read end
echo ""

sed -n "$start,$end p;`expr $end + 1` q" $filename


