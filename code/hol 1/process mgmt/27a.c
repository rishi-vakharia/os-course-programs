#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    printf("Using execl\n");
    execl("/bin/ls", "ls", "-Rl", NULL);
    printf("Done\n");
    return 0;
}

// https://stackoverflow.com/questions/20823371/what-is-the-difference-between-the-functions-of-the-exec-family-of-system-calls