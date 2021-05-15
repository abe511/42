/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:46:16 by abalayan          #+#    #+#             */
/*   Updated: 2021/04/01 16:05:36 by abalayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				*wordbuilder(char *s, size_t len)
{
	char	*str;
	char	*substr;

	substr = (char *)malloc(sizeof(char) * len + 1);
	if (substr == NULL)
		return (NULL);
	str = substr;
	while (*s != '\0' && len--)
		*substr++ = *s++;
	*substr = '\0';
	return (str);
}

static unsigned int		wordcount(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
			i++;
		count++;
	}
	return (count);
}

static size_t			wordlen(char *str, char limit)
{
	size_t	len;

	len = 0;
	while (*str != '\0' && *str != limit)
	{
		len++;
		str++;
	}
	return (len);
}

char					**ft_split(const char *s1, char c)
{
	char			**str_arr;
	unsigned int	tokens;
	size_t			word_len;
	unsigned int	el;
	char			*word;

	el = 0;
	tokens = wordcount((char*)s1, c);
	if (!(str_arr = (char **)malloc(sizeof(char *) * tokens + 1)))
		return (NULL);
	while (*s1 != '\0' && el < tokens)
	{
		if (*s1 != c)
		{
			word_len = wordlen((char *)s1, c);
			word = wordbuilder((char *)s1, word_len);
			str_arr[el++] = word;
			s1 += word_len;
		}
		s1++;
	}
	str_arr[el] = NULL;
	return (str_arr);
}
