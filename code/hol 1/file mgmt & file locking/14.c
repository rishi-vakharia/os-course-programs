#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>

int main(int argc, char* argv[]){
    struct stat s;

    if(lstat(argv[1], &s)==-1)    printf("Error\n");

    switch(s.st_mode & S_IFMT){
        case S_IFBLK:   printf("block device\n");       break;
        case S_IFCHR:   printf("character device\n");   break;
        case S_IFREG:   printf("regular file\n");       break;
        case S_IFDIR:   printf("directory\n");          break;
        case S_IFIFO:   printf("FIFO/pipe\n");          break;
        case S_IFLNK:   printf("symlink\n");            break;
        case S_IFSOCK:  printf("socket\n");             break;
        default:        printf("unknown\n");            break;
    }
}
