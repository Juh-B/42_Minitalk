/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:11:28 by jcosta-b          #+#    #+#             */
/*   Updated: 2024/12/16 11:40:27 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	printf_specifiers(va_list args, char c)
{
	size_t	printed;

	printed = 0;
	if (c == 'c')
		printed += printf_putchar(va_arg(args, int));
	else if (c == 's')
		printed += printf_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		printed += printf_putnbr(va_arg(args, int));
	else if (c == 'u')
		printed += printf_putnbr_unsig(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		printed += printf_puthex(va_arg(args, unsigned int), c);
	else if (c == 'p')
		printed += printf_putptr(args, c);
	else if (c == '%')
		printed += printf_putchar('%');
	return (printed);
}

int	ft_printf(const char *fmt_str, ...)
{
	va_list	args;
	int		i;
	size_t	printed;

	if (!fmt_str)
		return (-1);
	va_start(args, fmt_str);
	i = 0;
	printed = 0;
	while (fmt_str[i] != '\0')
	{
		if (fmt_str[i] == '%' && fmt_str[i + 1] != '\0')
		{
			i++;
			printed += printf_specifiers(args, fmt_str[i]);
			i++;
		}
		else
		{
			printed += printf_putchar(fmt_str[i]);
			i++;
		}
	}
	va_end(args);
	return (printed);
}
