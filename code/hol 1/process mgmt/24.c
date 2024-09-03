#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>

/* Orphan Process: A process whose parent process no more exists 
 * i.e. either finished or terminated without waiting for its child process to 
 * terminate is called an orphan process.
 */

int main()
{
    int ret = fork();

    if (!ret)
    {
        printf("In child process...\n");
        printf("Before: pid = %d, parent pid = %d\n", getpid(), getppid());
        sleep(5);       //child sleeps, parent terminates, child becomes orphan 
        printf("After: pid = %d, parent pid = %d\n", getpid(), getppid());
    }
    else
    {
        printf("In parent process...\n");
        printf("pid: %d\n", getpid());
    }
    return 0;
}