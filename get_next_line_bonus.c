/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 01:32:16 by juperez           #+#    #+#             */
/*   Updated: 2024/06/05 14:12:11 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_init_stash(char *stash)
{
	int	i;

	i = 0;
	while (i < (BUFFER_SIZE + 1))
	{
		stash[i] = '\0';
		i++;
	}
}

static char	*ft_get_left_line(char *stash, t_left *left)
{
	left->is_line = false;
	if (*stash)
	{
		left->end_line = ft_strchr(stash, '\n');
		if (left->end_line++)
		{
			left->is_line = true;
			left->length = left->end_line - stash;
			left->line = ft_strndup(stash, left->length);
			ft_strlcpy(stash, left->end_line, ft_strlen(left->end_line) + 1);
		}
		else
		{
			left->line = ft_strndup(stash, ft_strlen(stash));
			ft_init_stash(stash);
		}
	}
	else
		left->line = ft_strndup("", 0);
	return (left->line);
}

static char	*ft_split_buffer(
	char *buffer, char *end_line, char *stash, char *line)
{
	*end_line = '\0';
	line = ft_strjoin(line, buffer, true);
	if (!line)
		return (ft_init_stash(stash), NULL);
	ft_strlcpy(stash, end_line + 1, ft_strlen(end_line + 1) + 1);
	return (line);
}

static char	*ft_read_fd(int fd, char *line, char *stash)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*end_line;
	int		bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		end_line = ft_strchr(buffer, '\n');
		if (end_line)
			return (ft_split_buffer(buffer, end_line, stash, line));
		line = ft_strjoin(line, buffer, false);
		if (!line)
			return (ft_init_stash(stash), NULL);
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	ft_init_stash(stash);
	if ((!*line && bytes == 0) || bytes == -1)
		return (free(line), NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	stash[FOPEN_MAX][BUFFER_SIZE + 1];
	t_left		left;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		return (ft_init_stash(stash[fd]), NULL);
	left.line = ft_get_left_line(stash[fd], &left);
	if (!left.line)
		return (NULL);
	if (left.is_line)
		return (left.line);
	return (ft_read_fd(fd, left.line, stash[fd]));
}
