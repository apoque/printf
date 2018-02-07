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
#include <stdio.h>

void		ft_treatment(t_printf *p)
{
	if (p->format[p->idx2] == 'i' || p->format[p->idx2] == 'd')
		ft_nb(p);
	p->idx2++;
}

void		ft_txt(t_printf *p)
{
	char	*tmp;
	int	i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (p->idx2 - p->idx1 + 1));
	tmp[p->idx2 - p->idx1] = '\0';
	while (p->idx1 < p->idx2)
	{
		tmp[i] = p->format[p->idx1];
		p->idx1++;
		i++;
	}
	p->add = ft_strdup(tmp);
	free(tmp);
}

void		ft_buf(t_printf *p)
{
	char	*tmp;

	tmp = ft_strdup(p->buf);
	free(p->buf);
	p->buf = ft_strjoin(tmp, p->add);
	free(tmp);
	free(p->add);
}

void		ft_init_p(t_printf *p, const char *format)
{
	p->buf = (char *)malloc(sizeof(char) * 1);
	p->add = (char *)malloc(sizeof(char) * 1);
	p->buf[0] = '\0';
	p->add[0] = '\0';
	p->idx1 = 0;
	p->idx2 = 0;
	p->conv = 0;
	p->format = format;
}

int			ft_printf(const char *format, ...)
{
	t_printf p;

	ft_init_p(&p, format);
	va_start(p.ap, format);
	while (p.format[p.idx1])
	{
		p.idx1 = p.idx2;
		while (p.format[p.idx2] != '%' && p.format[p.idx2] != '\0')
			p.idx2++;
		if (p.idx1 != p.idx2)
		{
			ft_txt(&p);
			ft_buf(&p);
		}
		if (p.format[p.idx2++] == '%')
			ft_treatment(&p);
	}
	va_end(p.ap);
	ft_putstr(p.buf);
	return (ft_strlen(p.buf));
}
