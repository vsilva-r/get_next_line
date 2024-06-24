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

char	*get_line(char *store, char *newline)
{
	char	*line;

	if (!newline || !store)
		return (store);
	line = malloc(newline + 1 - store);
	if (!line)
		return(NULL);
	while (store < newline)
		*(line++) = *(store++);
	*line = '\0';
	return (line);
}

char	*endofstr(char *str)
{
	while (str && *str)
		str++;
	return (str);
}
char	*strealloc(char *oldstr, int extra_size)
{
	char	*newstr;
	int	i;

	if (!oldstr)
		return (NULL);
	newstr = oldstr;
	while (newstr && *newstr)
		newstr++;
	newstr = (char *)malloc(newstr - oldstr + 1 + extra_size);
	if (!newstr)
		return (NULL);
	i = 0;
	while (*oldstr)
		newstr[i++] = *(oldstr++);
	while (extra_size-- >= 0)
		newstr[i++] = '\0';
	free(oldstr);
	return (newstr);
}

/*
t_split	split_store(store, newline)
{
	t_split	split;

	if (!newline)
	{
		split.line = store;
		free(store);
		split.store = NULL;
	}
	else
	{
		split.line = get_line(store, newline);
		free(store);
		split.store = strealloc(newline + 1, 0);
	}
	return (split);
}
*/