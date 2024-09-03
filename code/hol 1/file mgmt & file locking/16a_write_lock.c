#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>

/* WRITE Lock: only one process can write at one time. No other process can read/write at that time. */

/*
 * The program will print "Waiting to write..." and then "Writing...(enter to unlock)". 
 * It will then wait for you to press Enter. While it's waiting, you can open another terminal 
 * and try to open the same file with a text editor or another instance of the same program. 
 * You'll see that you can't write to the file until you press Enter in the first terminal to unlock it.
 */

int main(){

    struct flock lock;
    int fd = open("newfile.txt", O_CREAT|O_RDWR, 0755);
    lock.l_type=F_WRLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=0;
    lock.l_pid=getpid();

    printf("Waiting to write...\n");

    fcntl(fd, F_SETLKW, &lock);
    printf("Writing...(enter to unlock)\n");
    getchar();

    lock.l_type=F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);
}