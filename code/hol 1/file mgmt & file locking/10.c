#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){

    int fd= open("newfile.txt", O_CREAT|O_RDWR, 0755);
    write(fd, "Hello my name is Rishi", 10);
    printf("lseek returned %ld\n", lseek(fd, 10, SEEK_CUR));
    write(fd, "Hello I am back. 10 bytes", 10);
    close(fd);
}

//od -a newfile.txt