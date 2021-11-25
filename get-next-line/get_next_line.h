/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 01:06:37 by ********          #+#    #+#             */
/*   Updated: 2021/10/30 01:10:30 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 96
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_read_buf(char **buffer, int fd);
int		ft_find_nl(char *buffer, int *nl);
void	ft_build_line(char **line, char **buffer);
void	ft_append_buffer(char **line, char *buffer, int nl);
void	ft_split_buffer(char **buffer, int nl);

#endif
