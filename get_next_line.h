/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsilva-r <vsilva-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:18:30 by vsilva-r          #+#    #+#             */
/*   Updated: 2024/05/29 15:18:30 by vsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_stash
{
	char	buffer[BUFFER_SIZE + 1];
	int	newline;
}		t_stash;

char	*get_next_line(int fd);
void	gnl_bzero(char *str, size_t size);
int	findnewline(char *stash);
char	*xstract(char *stash, int newline);
char	*gnl_strjoin(char *str1, char *str2);
/*
char	*get_line(char *store, char *newline);
char	*strealloc(char *oldstr, int extra_size);
char	*endofstr(char *str);
*/

#endif
