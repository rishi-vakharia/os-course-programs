#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	//Creating a file with name argv[1]
	creat(argv[1], O_CREAT | 0777);

	//Creating soft link by the name symlnk1
	symlink(argv[1], "symlnk1");

	//Creating hardlink by the name hrdlnk1
	link(argv[1], "hrdlnk1");

	//Creating a named pipe by the name myfifo
	mknod("myfifo1", S_IFIFO | 0777, 0);

	return 0;
}