/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:35:05 by abalayan          #+#    #+#             */
/*   Updated: 2021/03/30 20:49:08 by abalayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_numlen(n, n < 0);
	str = (char *)malloc((sizeof(char) * len) + 1);
	if (str == NULL)
		return (NULL);
	str[0] = (n == 0) ? '0' : str[0];
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
		{
			str[len-- - 1] = '8';
			n /= 10;
		}
		n *= -1;
	}
	while (n != 0 && len >= 0)
	{
		str[len-- - 1] = n % 10 + 48;
		n /= 10;
	}
	return (str);
}
