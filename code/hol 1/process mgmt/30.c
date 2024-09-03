#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/stat.h>

int main()
{
    if (!fork())
    {
        printf("child pid : %d\n", getpid());
        setsid();
        chdir("/");
        umask(0);
        while (1)
        {
            sleep(5);
            printf("this is Daemon Process \n");
        }
    }
    else
        exit(0);
}

// https://www.thegeekstuff.com/2012/02/c-daemon-process/#:~:text=A%20daemon%20process%20is%20a,background%20without%20any%20user%20interaction.