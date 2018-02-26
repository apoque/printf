/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 19:34:13 by apoque            #+#    #+#             */
/*   Updated: 2018/02/13 21:26:18 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


void	ft_print_x2(t_printf *p, unsigned long u, int zeros)
{
	if ((p->flag[DIESE] == 1 && u != 0) || (p->flag[DIESE] == 1 && p->dot == 1))
	{
		ft_putchar('0');
		if (p->format[p->idx2] == 'X')
			ft_putchar('X');
		else
			ft_putchar('x');
		p->len += 2;
	}
	if (p->flag[MORE] == 1)
	{
		ft_putchar('+');
		p->len++;
	}
	if (p->size > 0 && p->flag[ZERO] == 1 && p->dot == 0 && p->flag[DIESE] != 1)
		ft_put_space(p, 1);
	if (zeros > 0)
		ft_put_precision(p, zeros);
	if (!(p->dot == 1 && u == 0))
		ft_buf(p);
	if (p->size > 0 && (p->flag[LESS] == 1))
		ft_put_space(p, 2);
}

void	ft_print_x(t_printf *p, unsigned long u)
{
	int	zeros;
	int	tmp;


	tmp = (p->flag[DIESE] == 1 && (u != 0 || p->dot == 1)) ? 1 : 0;
	zeros = p->precision - ft_strlen(p->buf) - tmp;
	zeros = (p->dot == 1 && u == 0) ? zeros + 1 : zeros;
	zeros = (zeros < 0) ? 0 : zeros;
	tmp = ((p->flag[DIESE] == 1 && (u != 0 || p->dot == 1)) && zeros == 0) ? 1 : 0;
	p->size = p->size - (zeros + ft_strlen(p->buf) + p->flag[MORE] + tmp);
	p->size = (p->dot == 1 && u == 0 && p->flag[DIESE] != 1) ? p->size + 1 : p->size;
	if (p->flag[SPACE] == 1 && p->flag[MORE] == 0)
		p->size--;
	if (p->size > 0 && (p->flag[ZERO] != 1 || p->dot == 1 || p->flag[DIESE] == 1) && p->flag[LESS] != 1)
		ft_put_space(p, 2);
	if (p->flag[SPACE] == 1 && p->flag[MORE] == 0)
	{
		ft_putchar(' ');
		p->len++;
	}
	ft_print_x2(p, u, zeros);
}

void	ft_xint(t_printf *p)
{
	unsigned int		o;
	unsigned long long	u;
	size_t				z;

	if (p->txt == 1)
		ft_buf(p);
	if (p->modif[Z] == 1)
	{
		z = va_arg(p->ap, size_t);
		p->buf = ft_itoabase_u(z, "0123456789abcdef");
		ft_print_x(p, z);
	}
	else if (p->modif[J] == 1)
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

void		ft_xmajint(t_printf *p)
{
	unsigned long	o;

	if (p->txt == 1)
		ft_buf(p);
	if (p->modif[L] == 1)
	o = (unsigned long int)va_arg(p->ap, unsigned long int);
	else
	o = (unsigned long long int)va_arg(p->ap, unsigned long long int);
	p->buf = ft_itoabase_u(o, "0123456789ABCDEF");
	ft_print_x(p, o);
}



/*void	ft_xmajint(t_printf *p)
{
	unsigned int	nb;
	int				i;

	if (p->txt == 1)
		ft_buf(p);
	i = 0;
	nb = (unsigned int)va_arg(p->ap, unsigned int);
	p->buf = ft_uitoabase(nb, 16);
	while (p->buf[i])
	{
		p->buf[i] = ft_toupper(p->buf[i]);
		i++;
	}
	ft_buf(p);
}

void	ft_xint(t_printf *p)
{
	unsigned int	nb;

	if (p->txt == 1)
		ft_buf(p);
	nb = (unsigned int)va_arg(p->ap, unsigned int);
	p->buf = ft_uitoabase(nb, 16);
	ft_buf(p);
}*/
