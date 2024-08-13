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
#ifndef NEWLINE_INDEX
# define NEWLINE_INDEX(x) ((stash.buffer)[stash.newline + x])
# define FLAG(x) (NEWLINE_INDEX(x) == '\n')
#endif 

/* 	So how does this work? LOL
	1. It starts by xtracting whatever is on the current stash buffer,
	   up until the next newline character. The location of the text 
	   xtracted so far is saved on the variable stash.newline. 
	2. If it reaches the end of the buffer without finding a newline char,
	   it enters the if condition, whereby it will bzero the current stash
	   and read BUFFER_SIZE more bytes into it. 
	3. If any bytes at all were read into the buffer, it will call another 
	   instance of get_next_line to xtract more text, and append it to the 
	   previously xtracted text with gnl_strjoin. 
	4. If no bytes were read, or if a newline has been found, it will return
	   all the text appended so far, and exit. 
*/

char	*get_next_line(int fd)
{
	static t_stash	stash;
	char	*line;
	int	read_out;

	if (BUFFER_SIZE < 1)
		return (NULL);
	if (stash.buffer[BUFFER_SIZE] != 0)
		gnl_bzero(&stash, BUFFER_SIZE + 1);
	line = xstract(&stash);
	if (!NEWLINE_INDEX(0))
	{
		gnl_bzero(&stash, BUFFER_SIZE);
		read_out = read(fd, stash.buffer, BUFFER_SIZE);
		if (read_out < 0)
			return (free(line), NULL);
		else if (read_out > 0)
			return (gnl_strjoin(line, get_next_line(fd)));
	}
	stash.newline = (stash.newline + 1) % (BUFFER_SIZE + 1);
	return (line);
}