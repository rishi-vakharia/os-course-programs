#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

int main(){

    fd_set fds;         //file descriptor set
    struct timeval tv;
    int retval, data;

    FD_ZERO(&fds);      //clear set
    FD_SET(0, &fds);    //add fd 0(STDIN) to set

    tv.tv_sec=10;       //wait for 10 seconds
    tv.tv_usec=0;
    
    retval=select(1, &fds, NULL, NULL, &tv);

    if(retval){
        scanf("%d", &data);
        printf("Data is available within 10 seconds\n");
    }
    else 
        printf("Data is NOT available within 10 seconds\n");
}