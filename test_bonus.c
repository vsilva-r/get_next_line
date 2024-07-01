#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int	files[3];
	int	i = 0;
	char	*line;

	
	files[0] = open("test1.txt", O_RDONLY);
	files[1] = open("test2.txt", O_RDONLY);
	files[2] = open("test3.txt", O_RDONLY);
	
	while (i < 20)
	{
		line = get_next_line(files[i % 3]);
		printf("\033[1;31mLOREM\033[1;0m\t%2d/20: %s\n", i++, line);
		free(line);

		line = get_next_line(files[i % 3]);
		printf("\033[1;31mREGIO\033[1;0m\t%2d/20: %s\n", i++, line);
		free(line);

		line = get_next_line(files[i % 3]);
		printf("\033[1;31mLIANOR\033[1;0m\t%2d/20: %s\n", i++, line);
		free(line);
	}
	
	close(files[0]);
	close(files[1]);
	close(files[2]);
}
