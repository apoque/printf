/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:11:11 by apoque            #+#    #+#             */
/*   Updated: 2018/02/13 22:31:52 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_treatment(t_printf *p)
{
	int	a;

	a = 1;
	if (p->format[p->idx2] == 'u')
		ft_uint(p);
	else if (p->format[p->idx2] == 'x') 
		ft_xint(p);
	else if (p->format[p->idx2] == 'X')
		ft_xmajint(p);
	else if (p->format[p->idx2] == 'o')
		ft_oint(p);
	else if (p->format[p->idx2] == 'O')
		ft_omajint(p);
	else if (p->format[p->idx2] == 'D' || ((p->format[p->idx2] == 'd' || p->format[p->idx2] == 'i') && (p->modif[L] == 1 || p->modif[LL] == 1)))
		ft_long(p);
	else if (p->format[p->idx2] == 's' && p->modif[L] != 1)
			ft_str(p);
	else if (p->format[p->idx2] == 'i' || p->format[p->idx2] == 'd')
		ft_int(p);

		else
		{
			a = 0;
			ft_treatment2(p);
		}
	(a == 1) ? p->idx2++ : a--;
}

void		ft_txt(t_printf *p)
{
	char	*tmp;
	int	i;

	i = 0;
	p->txt = 1;
	tmp = (char *)malloc(sizeof(char) * (p->idx2 - p->idx1 + 1));
	tmp[p->idx2 - p->idx1] = '\0';
	while (p->idx1 < p->idx2)
	{
		tmp[i] = p->format[p->idx1];
		p->idx1++;
		i++;
	}
	p->buf = ft_strdup(tmp);
	free(tmp);
}

void		ft_buf(t_printf *p)
{
	char	*tmp;

	tmp = ft_strdup(p->buf);
	p->buf = ft_strdup(p->buf);
	p->len = p->len + ft_strlen(tmp);
	ft_putstr(tmp);
	free(p->buf);
	free(tmp);
}

void		ft_init_p(t_printf *p, const char *format)
{
	p->buf = (char *)malloc(sizeof(char) * 1);
	p->buf[0] = '\0';
	p->idx1 = 0;
	p->idx2 = 0;
	p->len = 0;
	p->error = 0;
	p->format = format;
}

int			ft_printf(const char *format, ...)
{
	t_printf p;

	ft_init_p(&p, format);
	va_start(p.ap, format);
	while (p.format[p.idx1] && p.error != -1)
	{
		p.idx1 = p.idx2;
		p.txt = 0;
		while (p.format[p.idx2] != '%' && p.format[p.idx2] != '\0')
			p.idx2++;
		if (p.idx1 != p.idx2)
			ft_txt(&p);
		if (p.format[p.idx2++] == '%')
		{
			ft_init_opt(&p);
			ft_opt(&p);
			ft_treatment(&p);
		}
		if (p.txt == 1 && p.idx1 == ft_strlen((char *)p.format))
			ft_buf(&p);
	}
	va_end(p.ap);
	return (p.len = (p.error != -1) ? p.len : -1);
}
