#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    
    int fd = open("newfile.txt", O_CREAT|O_RDWR, 0755);
    int newfd = dup(fd);

    lseek(fd, 0, SEEK_END);
    write(fd, "Hello my friend\n", 16);

    lseek(newfd, 0, SEEK_END);
    write(newfd, "Hello again, using newfd this time\n", 35);

    close(fd);
    close(newfd);


    char buf[300];
    fd = open("newfile.txt", O_RDONLY);
    int size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    read(fd, buf, size);
    printf("%s", buf);
    close(fd);
}