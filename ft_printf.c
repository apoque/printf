/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:11:11 by apoque            #+#    #+#             */
/*   Updated: 2018/01/15 15:57:26 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *format, ...)
{
	int		size_printed;
	va_list	ap;

	size_printed = 0;
	va_start(ap, format);
	ft_init_ap(&ap);
	while (*format)
	{
		while (*format != '%')
		{
			write(1, format, 1);
			format++;
		}
	}

	return (size_printed);
}
