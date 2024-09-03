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
    struct ticket t;
    t.ticket_no=59;

    int fd= open("ticket_db.bin", O_CREAT|O_RDWR, 0755);
    write(fd, &t, sizeof(struct ticket));
    close(fd);
}