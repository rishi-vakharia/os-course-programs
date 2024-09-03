#!/bin/sh

# Using SED - Write a shell script to perform the following (input file “example.txt” will be given):


# Find all the lines containing our search pattern.
echo "Type in the word : " 
read word1
sed -n "/$word1/p" example.txt
echo "\n"

# Find all the lines not containing the search string.
echo "Type in the word : " 
read word1
sed "/$word1/d" example.txt
echo "\n"

# Find matching lines starting with a given pattern and ending in a second pattern
echo "Type in the starting word : "
read word1
echo "Type in the end word : "
read word2
sed -n "/^$word1.*$word2.$/p" example.txt
echo "\n"

# Print a file starting from a certain line until to the end of file
echo "Type in the starting line number: "
read num
sed -n "$num,$"p example.txt
echo "\n"

# Search a given pattern in a file and replace with a new pattern and display the file.
echo "Type in the given pattern : "
read word1
echo "Type in the new pattern : "
read word2
sed "s/$word1/$word2/g" example.txt
echo "\n"

# Insert a given string at the beginning of each line of the file.
echo "Type in the string to be added at the beginning of every line : "
read word1
sed "s/^/$word1/" example.txt
echo "\n"

# Insert a given string at the end of each line of the file
echo "Type in the string to be added at the end of every line : "
read word1
sed "s/$/$word1/" example.txt
echo "\n"
