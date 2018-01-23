/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:11:11 by apoque            #+#    #+#             */
/*   Updated: 2018/01/23 20:56:04 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_printf	ft_treatment(t_printf p)
{
	if (p.format[p.idx + 1] == 'i' || p.format[p.idx + 1] == 'd')
		p = ft_nb(p);
	return (p);
}

void		ft_init_p(t_printf *p, const char *format)
{
	p->size = 0;
	p->idx = 0;
	p->conv = 0;
	p->format = format;
}

int			ft_printf(const char *format, ...)
{
	t_printf p;

	ft_init_p(&p, format);
	va_start(p.ap, format);
	ft_init_ap(&p.ap);
	while (p.format[p.idx])
	{
		while (p.format[p.idx] != '%' && p.format[p.idx] != '\0')
		{
			write(1, &p.format[p.idx], 1); //optimisable
			p.idx++;
			p.size++;
		}
		if (p.format[p.idx] == '%')
			p = ft_treatment(p);
	}
	va_end(p.ap);
	return (p.size);
}
