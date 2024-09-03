#include<unistd.h>
#include<stdio.h>
#include<sys/time.h>

unsigned long long rdtsc(){
    unsigned long long dst;
    __asm__ __volatile__ ("rdtsc":"=A" (dst));
    return dst;
}

int main(){

    unsigned long long int start, end;
    start = rdtsc();                            //time stamp counter

    printf("getpid(): %d\n", getpid());

    end= rdtsc();
    int nano = (end-start)/1.4;
    printf("getpid() took %d nano sec\n", nano);
}