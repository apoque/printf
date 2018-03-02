/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 21:12:32 by apoque            #+#    #+#             */
/*   Updated: 2018/02/13 22:11:04 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_long2(t_printf *p, long i, int zeros)
{
	if (p->flag[MORE] == 1 && i >= 0)
	{
		ft_putchar('+');
		p->len++;
	}
	if (i < 0 && i != LONG_MIN)
	{
		ft_putchar('-');
		p->len++;
		i = -i;
	}
	if (p->size > 0 && (p->flag[ZERO] == 1 && p->precision == 0))
		ft_put_space(p, 1);
	if (zeros > 0)
		ft_put_precision(p, zeros);
	if (!(p->dot == 1 && i == 0))
	{
		p->buf = ft_ltoa(i);
		ft_buf(p);
	}
	if (p->size > 0 && (p->flag[LESS] == 1))
		ft_put_space(p, 2);
}


void	ft_long(t_printf *p)
{
	long	i;
	long	tmp;
	int		zeros;
	char	*str;

	if (p->txt == 1)
		ft_buf(p);
	i = va_arg(p->ap, long int);
	str = ft_ltoa((tmp = (i < 0) ? -i : i ));
	zeros = p->precision - ft_strlen(str);
	zeros = (p->dot == 1 && i == 0) ? zeros + 1 : zeros;
	zeros = (zeros < 0) ? 0 : zeros;
	free(str);
	str = ft_ltoa(i);
	p->size = p->size - (zeros + ft_strlen(str) + (tmp = (p->flag[MORE] == 1 && i >= 0) ? 1 : 0));
	free(str);
	p->size = (p->dot == 1 && i == 0) ? p->size + 1 : p->size;
	if (p->flag[SPACE] == 1 && i >= 0 && p->flag[MORE] == 0)
		p->size--;
	if (p->size > 0 && (p->flag[ZERO] != 1 || p->precision > 0) && (p->flag[LESS] != 1))
		ft_put_space(p, 2);
	if (p->flag[SPACE] == 1 && i >= 0 && p->flag[MORE] == 0)
	{
		ft_putchar(' ');
		p->len++;
	}
	ft_long2(p, i, zeros);
}

void		ft_put_space(t_printf *p, int flag)
{
	while (p->size != 0)
	{
		if (flag == 1)
			ft_putchar('0');
		if (flag == 2)
			ft_putchar(' ');
		p->len++;
		p->size--;
	}
}

void		ft_put_precision(t_printf *p, int zeros)
{
	while (zeros != 0)
	{
		ft_putchar('0');
		p->len++;
		zeros--;
	}
}
