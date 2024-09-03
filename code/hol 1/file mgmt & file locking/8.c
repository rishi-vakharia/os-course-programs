#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(){

    char c;
    int fd= open("myfile.txt", O_RDONLY);

    int n = read(fd, &c, 1);
    while(n!=0){
        if(c=='\n'){
            getchar();   
        }
        else
            printf("%c", c);
        n = read(fd, &c, 1);
    }
    printf("\n");
    close(fd);
}