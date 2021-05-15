/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:39:38 by abalayan          #+#    #+#             */
/*   Updated: 2021/03/25 15:43:08 by abalayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*dest;
	unsigned char	*source;

	ch = (unsigned char)c;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (n--)
	{
		*dest++ = *source++;
		if (*(dest - 1) == ch)
			return (dest);
	}
	return (NULL);
}
