#!/bin/sh

# Count the number of block device files in /dev directory. 

count = $(ls -Rl /dev | grep ^b | wc -l)      #$(...) to run a command in a subshell in bash.

echo "Total number of block device files in /dev directory = $count"
