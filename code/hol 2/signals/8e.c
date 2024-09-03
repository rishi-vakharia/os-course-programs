#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>

void my_sig_handler(int sig)
{
    printf("Inside handler: %d\n", sig);
    printf("2 seconds over..\n");
}

int main()
{
    struct itimerval it_val;
    signal(SIGALRM, my_sig_handler);

    it_val.it_value.tv_sec = 2;
    it_val.it_value.tv_usec = 0;
    it_val.it_interval = it_val.it_value; //For generating after every interval of 2 secs
    int ret = setitimer(ITIMER_REAL, &it_val, NULL);
    if (ret == -1)
    {
        perror("Error calling setitimer()\n");
        exit(0);
    }
    for (int i = 1; i <= 5; i++)
    {
        printf("Main %d\n", i);
        sleep(1);
    }
    return 0;
}
