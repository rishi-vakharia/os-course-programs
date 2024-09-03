#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDONLY);

    if (fd < 0)
        perror("File does not exist");

    char* buf[1024]; //Assuming maximum number of lines to be 1024
    char c;
    int n, i = 0;
    int lc = 0; //linecount variable
    int line_sz[1024] = {0};

    while (n = read(fd, &c, 1))
    {
        //printf("%c", c);
        if (n == -1)
        {
            perror("Error while reading");
        }

        if (c == '\n') //new line character
        {
            buf[lc] = (char *)malloc(i * sizeof(char));
            i++;                      //For new line character
            lseek(fd, -i, SEEK_CUR);  //Moving i characters back from current position of file pointer
            read(fd, buf[lc], i - 1); //Not taking '\n' character
            line_sz[lc] = i - 1;
            //printf("%s\n", buf[lc]);
            lseek(fd, 1, SEEK_CUR); //For bypassing '\n' character
            lc++;                   //Incrementing line count
            i = 0;                  //Setting character count for new line to be 0
        }
        else
        {
            i++;
        }
    }
    buf[lc] = (char *)malloc(i * sizeof(char));
    lseek(fd, -i, SEEK_CUR);
    line_sz[lc] = i;
    read(fd, buf[lc], i); //backsalsh not included
    lc++;

    //Checking for duplicate lines
    int cnt = 0;
    for (int i = 0; i < lc; i++)
    {
        int flag = 0;
        for (int j = 0; j < i; j++)
        {
            if (line_sz[i] == line_sz[j])
            {
                int flag1 = 1;
                for (int k = 0; k < line_sz[i]; k++)
                {
                    if (buf[i][k] == buf[j][k])
                    {
                        flag1 = 1;
                    }
                    else
                    {
                        flag1 = 0;
                        break;
                    }
                }
                if (flag1 == 1)
                    flag = 1; //if duplicate
            }
        }
        if (flag == 0) //Non-duplicate
        {
            cnt++;
            printf("%s\n", buf[i]);
        }
    }
    printf("Total lines: %d and Total duplicates: %d\n", lc, lc - cnt);
    int ret = close(fd);
    return 0;
}