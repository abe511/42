/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 01:03:37 by ********          #+#    #+#             */
/*   Updated: 2021/10/30 01:03:42 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;

	dest = (char *)dst;
	source = (char *)src;
	if (dst > src)
		while (len--)
			dest[len] = source[len];
	if (dst < src)
		while (len--)
			*(dest++) = *(source++);
	return (dst);
}

void	ft_build_line(char **line, char **buffer)
{
	char	*temp;
	int		linelen;
	int		bufflen;

	linelen = ft_strlen(*line);
	bufflen = ft_strlen(*buffer);
	temp = (char *)malloc(sizeof(char) * linelen + bufflen + 1);
	if (*line != NULL)
	{
		ft_memmove(temp, *line, linelen);
		free(*line);
	}
	ft_memmove(temp + linelen, *buffer, bufflen);
	temp[linelen + bufflen] = '\0';
	*line = temp;
	free(*buffer);
	*buffer = NULL;
}

void	ft_append_buffer(char **line, char *buffer, int nl)
{
	int		linelen;
	char	*templine;

	templine = NULL;
	linelen = ft_strlen(*line);
	templine = (char *)malloc(sizeof(char) * (linelen + (nl + 1) + 1));
	ft_memmove(templine, *line, linelen);
	ft_memmove(templine + linelen, buffer, nl + 1);
	templine[linelen + nl + 1] = '\0';
	free(*line);
	*line = templine;
}

void	ft_split_buffer(char **buffer, int nl)
{
	int		bufflen;
	char	*tempbuff;

	tempbuff = NULL;
	bufflen = ft_strlen(*buffer);
	if (bufflen > 1)
	{
		tempbuff = (char *)malloc(sizeof(char) * (bufflen - nl));
		ft_memmove(tempbuff, *buffer + nl + 1, bufflen - nl - 1);
		tempbuff[bufflen - nl - 1] = '\0';
		free(*buffer);
		*buffer = tempbuff;
	}
	else
	{
		free(*buffer);
		*buffer = NULL;
	}
}
