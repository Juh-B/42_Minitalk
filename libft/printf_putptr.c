/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:13:40 by jcosta-b          #+#    #+#             */
/*   Updated: 2024/12/16 11:40:02 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	printf_putptr(va_list args, char c)
{
	unsigned long	ptr;
	size_t			printed;

	printed = 0;
	ptr = va_arg(args, unsigned long);
	if (ptr == 0)
		printed += printf_putstr("(nil)");
	else
	{
		printed += printf_putstr("0x");
		printed += printf_puthex(ptr, c);
	}
	return (printed);
}
