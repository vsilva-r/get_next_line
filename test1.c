#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	
	int	file1;
	int	i = 0;
	char	*line;

	
	file1 = open("test1.txt", O_RDONLY);

	i = printf("File opened with fd = %d\n", file1);
	printf("What the fuck? %d\n", i);
	i = 0;
	/*line = get_next_line(file1);
	printf("Iteration %2d/20: %s\n", i, line);
	free(line);*/
	
	
	while (i++ < 3)
	{
		line = get_next_line(file1);
		printf("Iteration %2d/20: %s\n", i, line);
		free(line);
	}
	
	close(file1);
}
