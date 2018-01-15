/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:24:04 by apoque            #+#    #+#             */
/*   Updated: 2018/01/15 16:01:08 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_init_ap(va_list *ap)
{
	int		d;
	char	c;
	char	*s;

	d = va_arg(*ap, int);
	c = (char)va_arg(*ap, int);
	s = va_arg(*ap, char*);
	va_end(*ap);
}