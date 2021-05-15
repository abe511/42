/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:56:04 by abalayan          #+#    #+#             */
/*   Updated: 2021/03/30 20:39:06 by abalayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int num, int sign)
{
	int	len;

	len = sign || (num == 0) ? 1 : 0;
	if (sign)
		num *= -1;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}
