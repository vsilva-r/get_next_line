#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#define BUFFER_SIZE 10

int main()
{
	
	int	fd1;
	int	i = 0;
	char	*line;

	fd1 = open("test4.txt", O_RDONLY);
	i = 0;
	line = "";
	while (line || (i > 100))
	{
		line = get_next_line(fd1);
		printf("%d: %s", fd1, line);
		free(line);
		i++;
	}
	close(fd1);
}
