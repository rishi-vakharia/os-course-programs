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

    struct flock lock;
    int fd = open("ticket_db.bin", O_RDWR);

    lock.l_type=F_WRLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=sizeof(struct ticket);
    lock.l_pid=getpid();
    fcntl(fd, F_SETLKW, &lock);

    struct ticket t;
    read(fd, &t, sizeof(struct ticket));
    printf("Press enter to book ticket no. %d ...", t.ticket_no);
    getchar();

    printf("Ticket no. %d booked\n", t.ticket_no);
    t.ticket_no=t.ticket_no+1;
    lseek(fd, 0, SEEK_SET);
    write(fd, &t, sizeof(struct ticket));

    lock.l_type=F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);
}