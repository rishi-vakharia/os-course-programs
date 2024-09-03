#!/bin/sh

# Give 4 choices to the user:
# 1. ls   2. pwd  3. who 4. exit 
# and execute the command as per the users choice.

echo "Enter:\n1 for ls\n2 for pwd\n3 for who\n4 for exit\n"
read choice
echo ""
case $choice in

    1)
    ls
    ;;

    2)
    pwd
    ;;

    3)
    who
    ;;

    4)
    exit
    ;;

esac
	
