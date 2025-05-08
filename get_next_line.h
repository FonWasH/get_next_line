/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 01:32:55 by juperez           #+#    #+#             */
/*   Updated: 2024/06/02 22:28:13 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_left
{
	size_t	length;
	char	*end_line;
	char	*line;
	bool	is_line;
}			t_left;

char		*get_next_line(int fd);
size_t		ft_strlen(char *str);
size_t		ft_strlcpy(char *dst, char *src, size_t size);
char		*ft_strchr(char *str, int c);
char		*ft_strndup(char *str, size_t len);
char		*ft_strjoin(char *s1, char *s2, bool nl);

#endif
