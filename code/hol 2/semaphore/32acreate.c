#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <fcntl.h>

union semun {
    int val;
    struct semid_ds *buffer;
    unsigned short *array;
};
struct ticket
{
    int cnt;
};

int main()
{
    key_t key = ftok(".", 't');
    int semid;
    semid = semget(key, 1, IPC_CREAT | IPC_EXCL | 0744);
    printf("Key %d \t Semid: %d\n", key, semid);
    union semun arg;
    arg.val = 1;
    semctl(semid, 0, SETVAL, arg);
    printf("Semaphore created successfully\n");
    int fd = open("32file.txt", O_RDWR);
    if (fd == -1)
    {
        printf("File open failed\n");
        exit(0);
    }
    struct ticket tkt = {0};
    write(fd, &tkt, sizeof(struct ticket));
    printf("Initialisation of file successful\n");
    close(fd);
    return 0;
}