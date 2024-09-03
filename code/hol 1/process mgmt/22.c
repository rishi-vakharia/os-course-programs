#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
    int fd = open("newfile.txt", O_CREAT|O_RDWR, 0755);

    int ret = fork();

    if (!ret) // Child Process
    {
        write(fd, "Writing from Child Process\n", 27);
    }
    else    // Parent Process
    {
        // sleep(1);
        write(fd, "Writing from Parent Process\n", 28);
        wait(0);
    }

    close(fd);
    return 0;
}