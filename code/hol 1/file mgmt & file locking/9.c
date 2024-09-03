#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    
    struct stat s;

    if(stat("myfile.txt", &s)!=0)      printf("Error\n");
    

    printf("a. inode no:                    %lu\n", s.st_ino); 
    printf("b. number of hard links:        %lu\n", s.st_nlink);
    printf("c. uid:                         %d\n", s.st_uid);
    printf("d. gid:                         %d\n", s.st_gid);
    printf("e. size:                        %ld\n", s.st_size);
    printf("f. block size:                  %ld\n", s.st_blksize);
    printf("g. number of blocks:            %ld\n", s.st_blocks);
    printf("h. time of last access:         %s", ctime(&s.st_atime));
    printf("i. time of last modification:   %s", ctime(&s.st_mtime));
    printf("j. time of last change:         %s", ctime(&s.st_ctime));
}