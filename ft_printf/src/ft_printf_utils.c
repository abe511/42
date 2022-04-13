/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a******n <a******n@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 08:41:46 by tumolabs          #+#    #+#             */
/*   Updated: 2022/03/15 08:56:13 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(unsigned char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	if (str == NULL)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

size_t	ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_reverse_string(unsigned char *s, int start, int end)
{
	unsigned char	temp;

	while (start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		++start;
		--end;
	}
}

int	ft_utoa_base(unsigned int num, unsigned char *buff, int b, char *chars)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (num)
	{
		i = num % b;
		buff[len] = chars[i];
		num /= b;
		++len;
	}
	buff[len] = '\0';
	ft_reverse_string(buff, 0, len - 1);
	return (len);
}
