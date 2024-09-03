#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/* Read and write are blocking system calls.*/
int main()
{
    int fd1[2], fd2[2];
    pipe(fd1);
    pipe(fd2);
    int ret = fork();
    if (ret > 0) //parent process
    {
        close(fd1[0]);
        close(fd2[1]);
        char buf[100];
        printf("In parent process...\n");
        write(fd1[1], "Hello There From Parent", 24);
        read(fd2[0], buf, 24);
        printf("%s\n", buf);
        wait(0);
    }
    else
    {
        close(fd1[1]);
        close(fd2[0]);
        char buf[100];
        read(fd1[0], buf, 25);
        printf("%s\n", buf);
        printf("In child process...\n");
        write(fd2[1], "Hello There From Child", 23);
    }
    return 0;
}