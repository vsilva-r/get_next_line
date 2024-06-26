/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <vsilva-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:18:30 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/05/29 15:18:30 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 42


#include <stdio.h>

void gnl_bzero(char *str, size_t size)
{	
	while (size)
		str[size--] = 0;
}

int	findnewline(char *buffer)
{
	int	i;

	//printf("Entered \033[1;32mFIND\033[1;0m\n");
	i = 0;
	while (buffer[i] && buffer[i] != '\n' && i < 500)
		i++;
	if (buffer[i] == '\n')
		i++;
	//printf("Exiting \033[1;31mFIND\033[1;0m, newline is %d\n", i);
	return (i);
}

char	*xstract(char *buffer, int newline)
{
	char	*line;
	int	i;

	//printf("Entered \033[1;32mXSTRACT\033[1;0m\n");
	if(!newline)
		newline = findnewline(buffer); //done
	line = malloc(newline + 1);
	i = 0;
	while (i < newline && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	//printf("Exiting \033[1;31mXSTRACT\033[1;0m, Line is %s\n", line);
	return (line);
}

/*char	*xstract(char *buffer, int newline)
{
	char	*line;
	
	if(!newline)
		newline = findnewline(buffer); //done
	line = malloc(newline + 1);
	printf("Line %s\n", line);
	while (newline && *buffer)
	{
		*(line++) = *(buffer++);
		newline--;
	}
	printf("Line %s\n", line);
	*line = '\0';
	printf("Line %s\n", line);
	return (line);
}*/

char	*gnl_strjoin(char *str1, char *str2)
{
	int	i;
	int	j;
	char	*joint;
	int	len;

	//printf("Entered \033[1;32mSTRJOIN\033[1;0m:\tstr1 is %s\n\t\tstr2 is %s\n", str1, str2);
	len = findnewline(str1) + findnewline(str2);
	joint = malloc(len + 1);
	if (!joint)
		return (NULL);
	i = 0;
	while (str1[i])
	{
		joint[i] = str1[i];
		i++;
	}
	free(str1);
	j = 0;
	while (str2[j])
	{
		joint[i + j] = str2[j];
		j++;
	}
	free(str2);
	//printf("Exiting \033[1;31mSTRJOIN\033[1;0m, line is %s\n", joint);
	return (joint);
}
		
