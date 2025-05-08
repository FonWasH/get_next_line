/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 01:38:20 by juperez           #+#    #+#             */
/*   Updated: 2024/05/28 00:06:50 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	if (size)
		dst[i] = '\0';
	return (size - 1);
}

char	*ft_strchr(char *str, int c)
{
	while (*str != (char)c)
	{
		if (!*str)
			return (NULL);
		str++;
	}
	return ((char *)str);
}

char	*ft_strndup(char *str, size_t len)
{
	char	*dst;

	dst = (char *)malloc(len + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, str, len + 1);
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2, bool nl)
{
	char	*str;
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc(len_s1 + len_s2 + nl + 1);
	if (!str)
		return (free(s1), NULL);
	i = 0;
	i += ft_strlcpy(str, s1, len_s1 + 1);
	free(s1);
	i += ft_strlcpy(str + i, s2, len_s2 + 1);
	if (nl)
	{
		str[i] = '\n';
		str[i + 1] = '\0';
	}
	return (str);
}
