#!/bin/sh

# Write a script to check how much space is used by each directory of a given 
# file system. The name of the file system has to be provided from the command 
# line parameter.

df -h $1
