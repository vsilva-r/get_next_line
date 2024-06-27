/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <vsilva-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:18:30 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/05/29 15:18:30 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define BUFFER_SIZE 10

char	*get_next_line(int fd)
{
	static t_stash	stash[_SC_OPEN_MAX];
	char	*line;
	int	read_out;

	//printf("Entered \033[1;32mGET_NEXT_LINE\033[1;0m\n");
	//printf("Buffer is \"%s\"\n", stash[fd].buffer);
	//printf("Newline is %d\n", stash[fd].newline);
	if (stash[fd].buffer[BUFFER_SIZE] != 0){
		//printf("Checkpoint NOBUF");
		gnl_bzero(stash[fd].buffer, BUFFER_SIZE + 1); //done
	}
	if (stash[fd].newline % (BUFFER_SIZE + 1)){
		//printf("Entered \033[1;33mIF\033[1;0m\n");
		line = xstract(stash[fd].buffer, stash[fd].newline);
	}
	else
	{
		//printf("Entered \033[1;33mELSE\033[1;0m\n");
		findnewline(&(stash[fd]));
		line = xstract((stash[fd].buffer + stash[fd].newline), 0);
		gnl_bzero(stash[fd].buffer, BUFFER_SIZE);
		read_out = read(fd, stash[fd].buffer, BUFFER_SIZE);
		//printf("\033[1;33mRead\033[1;0m %d:\t\"%s\"\n", read_out, stash[fd].buffer);
		if (read_out < 0)
			return (free(line), NULL);
		else if (read_out > 0)
		{
			findnewline(&(stash[fd]));
			return (gnl_strjoin(line, get_next_line(fd)));
		}
	}
	stash[fd].newline = 0;
	//printf("Exiting \033[1;31mGET_NEXT_LINE\033[1;0m\n");
	return (line);
}

	/*
	Allowed functions: read(), malloc(), free().

	DUVIDAS
	Q: Qual o tamanho da static? 
	A: É o tamanho do que lá estava antes + o novo buffer. 
	Q: Como parar o read sem ultrapassar a new line? 
	A: Ler um caratere de cada vez; Ou então crias uma nova string 'line' e mandas o resto para o novo buffer

	Is newline in static? -> Make new static and return line
	Read into buffer
	Is read = 0? -> Return static
	Is read -1? -> Return NULL
	Static = static + buffer
	Recursive call


	Store read bytes in 'line' until \n is found. Store extra bytes in 'store'.
	Store everything until \n in 'line'. Store extra in 'store'.
	Return line if it is complete, else return empty string
	OR call recursively until line is complete.

	static VAR TO STORE 

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	
	while (NOT NEW LINE)
		read_out = read(fd, buffer, BUFFER_SIZE);
		if (read_out < 0)
			return (NULL);
	
	return(buffer);
	*/
