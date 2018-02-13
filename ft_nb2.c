/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 19:34:13 by apoque            #+#    #+#             */
/*   Updated: 2018/02/13 20:31:53 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_uint(t_printf *p)
{
	p->buf = ft_uitoa(va_arg(p->ap, unsigned int));
	ft_buf(p);
}

void	ft_oint(t_printf *p)
{
	unsigned int	nb;

	nb = (unsigned int)va_arg(p->ap, unsigned int);
	p->buf = ft_itoabase(nb, 8);
	ft_buf(p);
}

void	ft_xmajint(t_printf *p)
{
	unsigned int	nb;
	int				i;

	i = 0;
	nb = (unsigned int)va_arg(p->ap, unsigned int);
	p->buf = ft_itoabase(nb, 16);
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

	nb = (unsigned int)va_arg(p->ap, unsigned int);
	p->buf = ft_itoabase(nb, 16);
	ft_buf(p);
}
