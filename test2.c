#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char *buffer = malloc(50);
	int fd = open("test1.txt", O_RDONLY);
	int rd = read(fd, buffer+45, 5);
	//printf("%p\n", malloc(0));
	printf("Read %d bytes from file %d: %s\n", rd, fd, buffer+45);
	free(buffer);
	close(fd);
}