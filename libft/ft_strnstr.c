/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 20:24:32 by abalayan          #+#    #+#             */
/*   Updated: 2021/03/23 18:26:07 by abalayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *s1, char *s2, size_t n)
{
	size_t i;
	size_t j;
	size_t s1_len;
	size_t s2_len;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s2_len > s1_len)
		return (NULL);
	if (s2_len == 0 || s1_len == 0)
		return ((char *)s1);
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		if (s1[i] == s2[j])
			while (s1[i + j] == s2[j] && (i + j) < n)
			{
				j++;
				if (s2[j] == '\0')
					return (&s1[i]);
			}
		i++;
	}
	return (NULL);
}
