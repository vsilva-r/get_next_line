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
#define BUFFER_SIZE 42

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char	*line;
	int	newline;

	if (stash[BUFFER_SIZE] != 0)
		stash = str_bzero(BUFFER_SIZE + 1); //done
	newline = findnewline(stash); //done
	if (newline)
	{
		line = xstract(stash, newline); //done
		stash = stash[newline];
	}
	else
	{
		line = xstract(stash[newline + 1], 0);
		read_out = read(fd, stash, BUFFER_SIZE);
		if (read_out < 0)
			return (NULL);
		if (read_out > 0)
			return (strjoin(line, get_next_line(fd)); //done	
	}
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
