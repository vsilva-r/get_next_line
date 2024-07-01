#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int	files[3];
	int	i = 0;
	char	*lines[3];

	
	files[0] = open("test4.txt", O_RDONLY);
	files[1] = open("test2.txt", O_RDONLY);
	files[2] = open("test3.txt", O_RDONLY);
	
	while ((lines[0] || lines[1] || lines[2]) || (i < 30))
	{
		lines[i % 3] = get_next_line(files[i % 3]);
		printf("\033[1;31m%d\033[1;0m: %s", files[i % 3], lines[i % 3]);
		free(lines[i++ % 3]);

		lines[i % 3] = get_next_line(files[i % 3]);
		printf("\033[1;31m%d\033[1;0m: %s", files[i % 3], lines[i % 3]);
		free(lines[i++ % 3]);

		lines[i % 3] = get_next_line(files[i % 3]);
		printf("\033[1;31m%d\033[1;0m: %s\n", files[i % 3], lines[i % 3]);
		free(lines[i++ % 3]);
	}
	close(files[0]);
	close(files[1]);
	close(files[2]);
}