//https://www.informit.com/articles/article.aspx?p=99706&seqNum=13
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(){

    int fd = open("newfile.txt", O_CREAT|O_WRONLY, 0744);
    
    int mode = fcntl(fd, F_GETFL) & O_ACCMODE;

    printf("Opening mode of 'newfile.txt' is: ");

    if(mode == O_RDONLY)
        printf("read only\n");
    else if(mode == O_WRONLY)
        printf("write only\n");
    else if(mode == O_RDWR)
        printf("read write\n");

    close(fd);
}