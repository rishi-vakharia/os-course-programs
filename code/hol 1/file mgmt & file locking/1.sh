#! /bin/bash
# rm hrdlnk
# rm sftlnk
# rm myfifo
touch myfile

#a)Soft link
ln -s myfile sftlnk
# ls -il
echo "myfile and sftlnk have different inode number"

#b) Hard link
ln myfile hrdlnk
# ls -il
echo "myfile and hrdlnk have the same inode number"

#c) FIFO(named pipe)
mkfifo myfifo
# ls -il
echo "myfifo file created"