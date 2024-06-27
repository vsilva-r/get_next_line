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

void	gnl_bzero(char *str, size_t size)
{	
	while (size)
		str[--size] = 0;
}

void	findnewline(t_stash *stash)
{
	int	i;

	////printf("Entered \033[1;32mFIND\033[1;0m\n");
	
	i = 0;
	if (!stash->buffer[0])
		return ;
	while (((stash->buffer)[i] != 0) && ((stash->buffer)[i] != '\n'))
		i++;
	stash->newline = ++i % (BUFFER_SIZE + 1);
	//printf("\033[1;33mFIND\033[1;0m:\tNewline is %d\n", stash->newline);
	////printf("Exiting \033[1;31mFIND\033[1;0m\n");
}

char	*xstract(char *buffer, int newline)
{
	char	*line;
	int	i;

	////printf("Entered \033[1;32mXSTRACT\033[1;0m\n");
	if (!newline)
		newline = ft_strlen(buffer);
	line = malloc(newline + 1);
	i = 0;
	while (i < newline && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	//printf("\033[1;33mXSTRACT\033[1;0m: Extracted \"%s\"\n", line);
	////printf("Exiting \033[1;31mXSTRACT\033[1;0m\n");
	return (line);
}

/*char	*xstract(char *buffer, int newline)
{
	char	*line;
	
	if(!newline)
		newline = findnewline(buffer); //done
	line = malloc(newline + 1);
	////printf("Line %s\n", line);
	while (newline && *buffer)
	{
		*(line++) = *(buffer++);
		newline--;
	}
	////printf("Line %s\n", line);
	*line = '\0';
	////printf("Line %s\n", line);
	return (line);
}*/

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

char	*gnl_strjoin(char *str1, char *str2)
{
	int	i;
	int	j;
	char	*joint;
	size_t	len;

	//printf("Entered \033[1;32mSTRJOIN\033[1;0m:\tstr1 is \"%s\"\n", str1);
	//printf("\t\t\tstr2 is \"%s\"\n", str2);
	len = ft_strlen(str1) + ft_strlen(str2);
	joint = malloc(len + 2);
	if (!joint)
		return (NULL);
	i = 0;
	while (str1[i])
	{
		////printf("entrou1: %c\n", str1[i]);
		joint[i] = str1[i];
		i++;
	}
	//free(str1);
	j = 0;
	while (str2[j])
	{
		////printf("entrou2: %c\n", str2[j]);
		joint[i + j] = str2[j];
		j++;
	}
	joint[i + j + 1] = 'X';
	joint[i + j + 2] = '\0';
	//free(str2);
	//printf("Str_joint is \"%s\"\n", joint);
	//printf("Exiting \033[1;31mSTRJOIN\033[1;0m\n");
	return (joint);
}
		
