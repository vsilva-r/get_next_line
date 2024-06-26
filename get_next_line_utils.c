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

char	*str_bzero(size_t size)
{
	char	*str;
	
	while (size)
		str[size--] = 0;
	return (str);
}

int	findnewline(char *stash)
{
	int	i;

	while (stash[i] || stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	return (i);
}

char	*xstract(char *stash, int newline)
{
	char	*line;
	
	if(!newline)
		newline = ft_strlen(stash); //define
	line = malloc(newline + 1);
	while (newline && *stash)
	{
		*(line++) = *(stash++)
		newline--;
	}
	*line = '\0';
	return (line);
}

int	ft_strlen(char *str)
{
	int	i;

	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*joint;
	int	len;

	len = ft_strlen(str1) + ft_strlen(str2);
	joint = malloc(len + 1);
	if (!joint)
		return (NULL);
	while (*str1)
		*(joint++) = *(str1++);
	while (*str2)
		*(joint++) = *(str2++);
	return (joint);
}
		
