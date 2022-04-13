/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a******n <a******n@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 08:57:22 by tumolabs          #+#    #+#             */
/*   Updated: 2022/03/15 08:58:20 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_handle_conversion(char fmt, va_list argPtr);
int		ft_handle_decimal(int num);
int		ft_handle_uint(unsigned int num);
int		ft_handle_hex(unsigned int num, char fmt);
int		ft_handle_ptr(void *ptr, char *charset);
int		ft_putchar(unsigned char c);
int		ft_putstr(char *str);
size_t	ft_strlen(const char *str);
void	ft_reverse_string(unsigned char *s, int start, int end);
int		ft_utoa_base(unsigned int num, unsigned char *buff, int b, char *chars);

#endif
