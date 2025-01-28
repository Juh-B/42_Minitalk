/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_puthex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:12:02 by jcosta-b          #+#    #+#             */
/*   Updated: 2024/12/16 11:40:14 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	printf_putnbr_base(unsigned long n, const char *base)
{
	size_t	count;

	count = 0;
	if (n >= 16)
		count += printf_putnbr_base(n / 16, base);
	count += printf_putchar(base[n % 16]);
	return (count);
}

size_t	printf_puthex(unsigned long n, const char base_specifier)
{
	if (base_specifier == 'X')
		return (printf_putnbr_base(n, "0123456789ABCDEF"));
	else
		return (printf_putnbr_base(n, "0123456789abcdef"));
}
