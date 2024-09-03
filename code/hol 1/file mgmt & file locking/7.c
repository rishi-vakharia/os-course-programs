#include<fcntl.h>
#include<unistd.h>

#define MAX 10000

//gcc 7.c
//./a.out <filename> <filecopyname>

int main(int argc, char* argv[]){

    char buf[MAX];
    int fd= open(argv[1], O_RDONLY);
    int size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    read(fd, buf, size);

    int fd1= open(argv[2], O_CREAT|O_RDWR, 0755);
    write(fd1, buf, size);

    close(fd);
}