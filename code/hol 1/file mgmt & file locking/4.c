#include<fcntl.h>
#include<stdio.h>

int main(){
    
    //if file already exists: open the file in RDWR mode 
    //if file DNE: create the file with 0755 permissions
    int fd1=open("myfile1", O_CREAT|O_RDWR, 0755);

    //O_EXCL flag - open function will fail if the specified file already exists
    int fd2=open("myfile2", O_CREAT|O_EXCL|O_RDWR, 0755);
    
    if(fd1==-1)
        printf("Error\n");

    if(fd2==-1)
        printf("Error\n");
}