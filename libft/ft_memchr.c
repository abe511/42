/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:11:32 by abalayan          #+#    #+#             */
/*   Updated: 2021/04/01 16:10:57 by abalayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*source;

	ch = (unsigned char)c;
	source = (unsigned char *)s;
	while (n--)
	{
		if (*source == ch)
			return (source);
		source++;
	}
	return (NULL);
}
