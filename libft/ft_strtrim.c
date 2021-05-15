/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:50:10 by abalayan          #+#    #+#             */
/*   Updated: 2021/03/29 17:49:09 by abalayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) != NULL)
		if (s1[++start] == '\0')
			break ;
	if (start == end)
		return (ft_strdup(""));
	while (ft_strrchr(set, s1[end]) != NULL)
		end--;
	str = ft_substr(s1, (unsigned int)start, end - start + 1);
	return (str);
}
