/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a******n <a******n@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 08:41:00 by tumolabs          #+#    #+#             */
/*   Updated: 2022/03/15 08:49:50 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_decimal(int num)
{
	int				len;
	int				sign;
	unsigned char	buffer[sizeof(int) * 8 + 1];

	if (num == 0)
		return (write(1, "0", 1));
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	sign = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		sign = 1;
		num *= -1;
	}
	len = ft_utoa_base(num, buffer, 10, "0123456789");
	return (write(1, buffer, len) + sign);
}

int	ft_handle_uint(unsigned int num)
{
	unsigned char	buffer[sizeof(int) * 8 + 1];
	int				len;

	if (num == 0)
		return (write(1, "0", 1));
	len = 0;
	len = ft_utoa_base(num, buffer, 10, "0123456789");
	return (write(1, buffer, len));
}

int	ft_handle_hex(unsigned int num, char fmt)
{
	unsigned char	buffer[sizeof(int) * 8 + 1];
	int				len;

	if (num == 0)
		return (write(1, "0", 1));
	len = 0;
	if (fmt == 'X')
		len = ft_utoa_base(num, buffer, 16, "0123456789ABCDEF");
	else
		len = ft_utoa_base(num, buffer, 16, "0123456789abcdef");
	return (write(1, buffer, len));
}

int	ft_handle_ptr(void *ptr, char *charset)
{
	unsigned char	buffer[sizeof(long int) * 8 + 1];
	int				i;
	int				len;
	unsigned long	num;

	i = 0;
	len = 0;
	num = (unsigned long int)ptr;
	if (num == 0)
		return (write(1, "0x0", 3));
	write(1, "0x", 2);
	while (num)
	{
		i = num % 16;
		buffer[len] = charset[i];
		num /= 16;
		++len;
	}
	buffer[len] = '\0';
	ft_reverse_string(buffer, 0, len - 1);
	return (write(1, buffer, len) + 2);
}
