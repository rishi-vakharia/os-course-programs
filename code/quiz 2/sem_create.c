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
    semid = semget(key, 3, IPC_CREAT | IPC_EXCL | 0744);

    printf("Key %d \t Semid: %d\n", key, semid);
    static unsigned short semarr[3] = {1, 1, 1};
    union semun arg;
    arg.array = semarr;
    semctl(semid, 0, SETALL, arg);
    printf("Semaphore created successfully\n");
    int fd = open("train_file.txt", O_RDWR);
    if (fd == -1)
    {
        printf("File open failed\n");
        exit(0);
    }
    struct ticket train1 = {0};
    struct ticket train2 = {0};
    struct ticket train3 = {0};
    write(fd, &train1, sizeof(struct ticket));
    write(fd, &train2, sizeof(struct ticket));
    write(fd, &train3, sizeof(struct ticket));
    printf("Initialisation of file successful\n");
    close(fd);
    return 0;
}