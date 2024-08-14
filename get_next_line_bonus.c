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

char	*get_next_line(int fd)
{
	static t_stash	stash[_SC_OPEN_MAX];
	char			*line;
	int				read_out;

	if (BUFFER_SIZE < 1)
		return (NULL);
	if (stash[fd].buffer[BUFFER_SIZE] != 0)
		gnl_bzero(&stash[fd], BUFFER_SIZE + 1);
	line = xstract(&stash[fd]);
	if (!((stash[fd].buffer)[stash[fd].newline]))
	{
		gnl_bzero(&stash[fd], BUFFER_SIZE);
		read_out = read(fd, stash[fd].buffer, BUFFER_SIZE);
		if (read_out < 0)
			return (free(line), NULL);
		else if (read_out > 0)
			return (gnl_strjoin(line, get_next_line(fd)));
	}
	stash[fd].newline = (stash[fd].newline + 1) % (BUFFER_SIZE + 1);
	return (line);
}
