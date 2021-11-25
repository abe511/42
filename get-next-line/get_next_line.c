/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 00:56:32 by ********          #+#    #+#             */
/*   Updated: 2021/10/30 00:56:41 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf[1024];
	char		*line;
	int			nl;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	nl = -1;
	line = NULL;
	while ((ft_read_buf(&buf[fd], fd) > 0) && (ft_find_nl(buf[fd], &nl) == -1))
		ft_build_line(&line, &buf[fd]);
	if (nl >= 0)
	{
		ft_append_buffer(&line, buf[fd], nl);
		ft_split_buffer(&buf[fd], nl);
	}
	return (line);
}

int	ft_read_buf(char **buffer, int fd)
{
	int	bytes;
	int	bufflen;

	bytes = 0;
	if (*buffer != NULL)
	{
		bufflen = ft_strlen(*buffer);
		if (bufflen > 0)
			return (bufflen);
		free(*buffer);
	}
	*buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (*buffer == NULL)
		return (0);
	bytes = read(fd, *buffer, BUFFER_SIZE);
	if (bytes <= 0)
	{
		free(*buffer);
		*buffer = NULL;
	}
	else
		(*buffer)[bytes] = '\0';
	return (bytes);
}

int	ft_find_nl(char *buffer, int *nl)
{
	int	i;

	i = 0;
	if (buffer != NULL)
	{
		while (buffer[i] != '\0')
		{
			if (buffer[i] == '\n')
			{
				*nl = i;
				return (i);
			}
			i++;
		}
	}
	return (-1);
}
