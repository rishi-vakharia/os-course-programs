#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{   
    int fd1 =  creat("source3",O_CREAT|0777);
	int fd2 = creat("source4",O_CREAT|0777);
    int fd3 = creat("source5",O_RDWR|0777);
    printf("%d %d %d\n",fd1,fd2,fd3);
    //Random file descriptors
	return 0;
}
