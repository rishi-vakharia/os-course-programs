#!/bin/sh

# Write an interactive file-handling shell program that offers the 
# user choice of copying, removing, rename. Once the user has made a choice, 
# the program ask user for the necessary information, such as the file name, new name. 

echo "Enter:\n1 - copy file\n2 - delete file\n3 - rename file\n"
read choice 
echo ""
case $choice in

1)
echo "Enter file to copy"
read filename
echo "Enter destination directory"
read dest_dirname
cp $filename $dest_dirname
echo "$filename copied to $dest_dirname"
;;

2)
echo "Enter file to delete"
read filename 
rm $filename
echo "$filename deleted"
;;

3)
echo "Enter file to rename"
read filename
echo "Enter new filename"
read new_filename
mv $filename $new_filename
echo "$filename renamed to $new_filename"
;;

esac