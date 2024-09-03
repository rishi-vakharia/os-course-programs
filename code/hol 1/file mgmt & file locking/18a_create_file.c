#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>

struct ticket{
    int ticket_no;
};

int main(){
    struct ticket t[3];
    t[0].ticket_no=59;
    t[1].ticket_no=65;
    t[2].ticket_no=743;

    int fd= open("ticket_db2.bin", O_CREAT|O_RDWR, 0755);
    write(fd, t, 3*sizeof(struct ticket));
    close(fd);
}