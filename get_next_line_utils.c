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

void	gnl_bzero(t_stash *stash, size_t size)
{
	while (size)
		(stash->buffer)[--size] = 0;
	stash->newline = 0;
}

int	gnl_strlen(const char *s)
{
	int	i;

	i = 0;
	while ((s[i] != 0) && (s[i] != '\n'))
		i++;
	return (i + (s[i] == '\n'));
}

int	findnewline(t_stash *stash)
{
	int	i;

	i = 0;
	while ((((stash->buffer)[stash->newline + i]) != 0) && \
		(((stash->buffer)[stash->newline + i]) != '\n'))
		i++;
	return (i);
}

char	*xstract(t_stash *stash)
{
	char	*line;
	int		i;
	int		size;
	int		flag;

	size = findnewline(stash);
	flag = (((stash->buffer)[stash->newline + size]) == '\n');
	if (size + flag == 0)
		return (NULL);
	line = malloc(size + flag + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < (size + flag))
	{
		line[i] = ((stash->buffer)[stash->newline + i]);
		i++;
	}
	line[i] = '\0';
	stash->newline = (stash->newline + size);
	return (line);
}

char	*gnl_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*joint;

	if (!str1)
		return (str2);
	if (!str2)
		return (str1);
	joint = malloc(gnl_strlen(str1) + gnl_strlen(str2) + 1);
	if (!joint)
		return (NULL);
	i = -1;
	while (str1[++i])
		joint[i] = str1[i];
	free(str1);
	j = -1;
	while (str2[++j])
		joint[i + j] = str2[j];
	joint[i + j] = '\0';
	free(str2);
	return (joint);
}
