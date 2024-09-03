#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

/* 
 * After the 10th second, the timer will trigger, but since there's no signal 
 * handler for SIGALRM, the default action (which is to terminate the process) 
 * will be taken.
 */

int main()
{
    struct itimerval it_val;
    it_val.it_value.tv_sec = 10;
    it_val.it_value.tv_usec = 10;
    it_val.it_interval = it_val.it_value; //For generating after every interval of 2 secs
    int ret = setitimer(ITIMER_REAL, &it_val, NULL);
    if (ret == -1)
    {
        perror("Error calling setitimer()\n");
        exit(0);
    }
    printf("Return value of setitimer: %d\n", ret);
    for (int i = 1; i <= 11; i++)
    {
        sleep(1);
        printf("%d secs over\n", i);
    }
    return 0;
}