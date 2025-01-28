/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:12:53 by jcosta-b          #+#    #+#             */
/*   Updated: 2024/12/16 11:39:54 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	printf_putstr(char *s)
{
	int	i;

	if (s == NULL)
		return (printf_putstr("(null)"));
	i = 0;
	while (s[i])
		i += printf_putchar(s[i]);
	return (i);
}
