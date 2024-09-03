#!/bin/sh

# cmd line arg --> output
# IIT --> NIT
# NIT --> IIT
# else --> stderr

case $1 in
    IIT)
    echo "NIT"
    ;;
    NIT)
    echo "IIT"
    ;;
    *)
    echo "STDERR"
    ;;
esac