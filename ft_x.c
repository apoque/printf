/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 19:34:13 by apoque            #+#    #+#             */
/*   Updated: 2018/03/13 17:42:36 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#define S p->size

void	ft_print_x2(t_printf *p, unsigned long u, int zeros)
{
	if (S > 0 && (p->flag[ZERO] != 1 || p->dot == 1) &&
			p->flag[LESS] != 1)
		ft_put_space(p, 2);
	if (((p->flag[DIESE] == 1 && u != 0) ||
		(p->flag[DIESE] == 1 && p->dot == 1 && u != 0)) || p->flag[J] == -5)
	{
		ft_putchar('0');
		if (p->format[p->idx2] == 'X')
			ft_putchar('X');
		else
			ft_putchar('x');
		p->len += 2;
	}
	if (S > 0 && p->flag[ZERO] == 1 && p->dot != 1 && p->flag[LESS] != 1)
		ft_put_space(p, 1);
	if (zeros > 0)
		ft_put_precision(p, zeros);
	if (!(p->dot == 1 && u == 0))
		ft_buf(p);
	if (S > 0 && (p->flag[LESS] == 1))
		ft_put_space(p, 2);
}

void	ft_print_x(t_printf *p, unsigned long u)
{
	int	zeros;
	int	tmp;

	zeros = p->precision - ft_strlen(p->buf);
	zeros = (p->dot == 1 && u == 0) ? zeros + 1 : zeros;
	zeros = (zeros < 0) ? 0 : zeros;
	tmp = ((p->flag[DIESE] == 1 && (u != 0 || p->dot == 1))) ? 2 : 0;
	S = S - (zeros + ft_strlen(p->buf) + p->flag[MORE] + tmp);
	S = (p->dot == 1 && u == 0 && p->flag[DIESE] != 1) ? S + 1 : S;
	ft_print_x2(p, u, zeros);
}

void	ft_xint2(t_printf *p)
{
	unsigned int		o;
	unsigned char		a;
	unsigned long long	u;

	if (p->modif[HH] == 1)
	{
		a = va_arg(p->ap, unsigned int);
		p->buf = ft_itoabase_u(a, "0123456789abcdef");
		ft_print_x(p, a);
	}
	else if (p->modif[J] == 1 || p->modif[LL] == 1)
	{
		u = va_arg(p->ap, unsigned long long);
		p->buf = ft_itoabase_u(u, "0123456789abcdef");
		ft_print_x(p, u);
	}
	else
	{
		o = va_arg(p->ap, unsigned int);
		p->buf = ft_itoabase_u(o, "0123456789abcdef");
		ft_print_x(p, o);
	}
}

void	ft_xint(t_printf *p)
{
	unsigned long		v;
	size_t				z;

	if (p->txt == 1)
		ft_buf(p);
	if (p->modif[Z] == 1)
	{
		z = va_arg(p->ap, size_t);
		p->buf = ft_itoabase_u(z, "0123456789abcdef");
		ft_print_x(p, z);
	}
	else if (p->modif[L] == 1)
	{
		v = va_arg(p->ap, unsigned long);
		p->buf = ft_itoabase_u(v, "0123456789abcdef");
		ft_print_x(p, v);
	}
	else
		ft_xint2(p);
}

void	ft_xmajint(t_printf *p)
{
	unsigned long	o;

	if (p->txt == 1)
		ft_buf(p);
	if (p->modif[L] == 1 || p->modif[Z] == 1)
		o = (unsigned long int)va_arg(p->ap, unsigned long int);
	else if (p->modif[LL] == 1 || p->modif[J] == 1)
		o = (unsigned long long int)va_arg(p->ap, unsigned long long int);
	else if (p->modif[HH] == 1)
		o = (unsigned char)va_arg(p->ap, unsigned int);
	else
		o = (unsigned int)va_arg(p->ap, unsigned int);
	p->buf = ft_itoabase_u(o, "0123456789ABCDEF");
	ft_print_x(p, o);
}
