/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a******n <a******n@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 08:29:25 by tumolabs          #+#    #+#             */
/*   Updated: 2022/03/15 08:51:27 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_conversion(char fmt, va_list ap)
{
	int	output;

	output = 0;
	if (fmt == 'c')
		output = ft_putchar(va_arg(ap, int));
	else if (fmt == 's')
		output = ft_putstr(va_arg(ap, char *));
	else if (fmt == 'p')
		output = ft_handle_ptr(va_arg(ap, void *), "0123456789abcdef");
	else if (fmt == 'd' || fmt == 'i')
		output = ft_handle_decimal(va_arg(ap, int));
	else if (fmt == 'u')
		output = ft_handle_uint(va_arg(ap, unsigned int));
	else if (fmt == 'x' || fmt == 'X')
		output = ft_handle_hex(va_arg(ap, unsigned int), fmt);
	else if (fmt == '%')
		output = write(1, "%", 1);
	return (output);
}

int	ft_printf(const char *str, ...)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	output;
	va_list			ap;

	va_start(ap, str);
	i = 0;
	start = 0;
	output = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			++i;
			output += write(1, str + start, i - (start + 1));
			output += ft_handle_conversion(str[i], ap);
			start = i + 1;
		}
		++i;
	}
	output += write(1, str + start, i - start);
	va_end(ap);
	return (output);
}
