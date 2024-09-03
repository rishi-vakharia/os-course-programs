#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>

struct ticket{
    int ticket_no;
};

void read_lock(int fd, int n){

    struct flock lock;
    lock.l_type=F_RDLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=(n-1)*sizeof(struct ticket);
    lock.l_len=sizeof(struct ticket);
    lock.l_pid=getpid();
    fcntl(fd, F_SETLKW, &lock);

    struct ticket t;
    lseek(fd, (n-1)*sizeof(struct ticket), SEEK_SET);
    read(fd, &t, sizeof(struct ticket));
    printf("Ticket no. %d is available. Press enter to exit...", t.ticket_no);
    getchar();

    lock.l_type=F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
}

void write_lock(int fd, int n){

    struct flock lock;
    lock.l_type=F_WRLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=(n-1)*sizeof(struct ticket);
    lock.l_len=sizeof(struct ticket);
    lock.l_pid=getpid();
    fcntl(fd, F_SETLKW, &lock);

    struct ticket t;
    lseek(fd, (n-1)*sizeof(struct ticket), SEEK_SET);
    read(fd, &t, sizeof(struct ticket));
    printf("Ticket no. %d is available. Press enter to book ticket no. %d...", t.ticket_no, t.ticket_no);
    getchar();

    printf("Ticket no. %d booked!\n", t.ticket_no);
    t.ticket_no++;
    lseek(fd, (n-1)*sizeof(struct ticket), SEEK_SET);
    write(fd, &t, sizeof(struct ticket));

    lock.l_type=F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
}

int main(){

    int fd = open("ticket_db2.bin", O_RDWR);

    int n, c;
    printf("Select train number(1, 2, 3): ");
    scanf("%d", &n);
    getchar();      //scanf() leaves the newline character in the buffer
    printf("\nPress 1 to check ticket availability (read lock)\nPress 2 to book a ticket (write lock)\n");
    scanf("%d", &c);
    getchar();      //scanf() leaves the newline character in the buffer
    printf("\n");

    if(c==1)
        read_lock(fd, n);
    else if(c==2)
        write_lock(fd, n);

    close(fd);
}