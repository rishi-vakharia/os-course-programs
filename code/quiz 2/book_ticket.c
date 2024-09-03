#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <fcntl.h>

struct ticket
{
    int cnt;
};

int main()
{
    key_t key = ftok(".", 't');
    int semid;
    semid = semget(key, 3, 0);
    printf("Key %d \t Semid: %d\n \n", key, semid);
    struct sembuf s[3] = {{0, -1, 0 | SEM_UNDO}, {1, -1, 0 | SEM_UNDO}, {2, -1, 0 | SEM_UNDO}};
    struct ticket tkt;
    printf("Before Entering the critical section\n\n");
    printf("Enter the train number you want to lock (1,2,3): ");
    int train_num;
    scanf("%d", &train_num);
    semop(semid, &s[(train_num - 1)], 1);
    printf("Inside critical section :----semaphore\n\n");
    int fd = open("train_file.txt", O_RDWR);
    if (fd == -1)
    {
        printf("File open failed\n");
        exit(0);
    }
    lseek(fd, (train_num - 1) * sizeof(struct ticket), SEEK_SET);
    read(fd, &tkt, sizeof(struct ticket));
    lseek(fd, (train_num - 1) * sizeof(struct ticket), SEEK_SET);
    tkt.cnt += 1;
    write(fd, &tkt, sizeof(struct ticket));
    close(fd);
    printf("Press Enter to Unlock the semaphore.\n");
    getchar();
    getchar();
    s[train_num - 1].sem_op = 1;
    semop(semid, &s[train_num - 1], 1);
    printf("Semaphore unlocked...Outside the critical section\n");
    printf("New ticket count for train %d : %d\n", train_num, tkt.cnt);

    return 0;
}