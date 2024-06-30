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

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define NEWLINE_INDEX_(x) (stash->buffer)[stash->newline + x]

void	gnl_bzero(char *str, size_t size)
{	
	while (size)
		str[--size] = 0;
}

int	findnewline(t_stash *stash)
{
	int	i;

	i = 0;
	while ((NEWLINE_INDEX_(i) != 0) && (NEWLINE_INDEX_(i) != '\n'))
		i++;
	//printf("\033[1;33mFIND\033[1;0m:\tNewline add %d\n", i);
	return (i);
}

char	*xstract(t_stash *stash)
{
	char	*line;
	int	i;
	int	size;

	size = findnewline(stash);
	line = malloc(size + 1);
	i = 0;
	while (i < size && NEWLINE_INDEX_(i))
	{
		line[i] = NEWLINE_INDEX_(i);
		i++;
	}
	line[i] = '\0';
	stash->newline = (stash->newline + size) % BUFFER_SIZE; /* ! */
	// (stash->newline += size) %= BUFFER_SIZE;
	//printf("\033[1;33mXSTRACT\033[1;0m: Extracted \"%s\"\n", line);
	return (line);
}

/*char	*xstract(char *buffer, int newline)
{
	char	*line;
	
	if(!newline)
		newline = findnewline(buffer); //done
	line = malloc(newline + 1);
	//printf("Line %s\n", line);
	while (newline && *buffer)
	{
		*(line++) = *(buffer++);
		newline--;
	}
	//printf("Line %s\n", line);
	*line = '\0';
	//printf("Line %s\n", line);
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

	len = ft_strlen(str1) + ft_strlen(str2);
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
	joint[i + j] = '\0';
	free(str2);
	return (joint);
}