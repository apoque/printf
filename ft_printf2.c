/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 21:14:51 by apoque            #+#    #+#             */
/*   Updated: 2018/02/13 22:32:27 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_treatment2(t_printf *p)
{
	int	a;

	a = 1;
	if (p->format[p->idx2] == 'S' || (p->format[p->idx2] == 's' && p->modif[L] == 1))
		ft_wstr(p);
	else if (p->format[p->idx2] == 'c' && p->modif[L] == 0)
		ft_char(p);
	else if (p->format[p->idx2] == 'U')
		ft_umajint(p);
	else if (p->format[p->idx2] == 'C' || (p->format[p->idx2] == 'c' && p->modif[L] == 1))
		ft_wchar(p);
	else
		a = 0;
	if (a == 1)
		p->idx2++;
}

void		ft_init_opt(t_printf *p)
{
	int	i;

	i = 0;
	while (i != 4)
	{
		p->flag[i] = 0;
		i++;
	}
	i = 0;
	while (i != 5)
	{
		p->modif[i] = 0;
		i++;
	}
	p->dot = 0;
	p->precision = 0;
	p->size = 0;
}

void		ft_opt_flag(t_printf *p)
{
	if (p->format[p->idx2] == '#')
	{
		p->flag[DIESE] = 1;
		p->idx2++;
	}
	else if (p->format[p->idx2] == '0')
	{
		p->flag[ZERO] = 1;
		p->idx2++;
	}
	else if (p->format[p->idx2] == '-')
	{
		p->flag[LESS] = 1;
		p->idx2++;
	}
	else if (p->format[p->idx2] == '+')
	{
		p->flag[MORE] = 1;
		p->idx2++;
	}
	else if (p->format[p->idx2] == ' ')
	{
		p->flag[SPACE] = 1;
		p->idx2++;
	}
}

void		ft_opt_specifier(t_printf *p)
{
	if ((p->format[p->idx2] == '-' || p->format[p->idx2] == '+' ||
				p->format[p->idx2] == '#' || p->format[p->idx2] == '0' ||
				p->format[p->idx2] == ' '))
		ft_opt_flag(p);
	if (ft_isdigit(p->format[p->idx2]) && p->format[p->idx2] != '0')
		ft_opt_size(p);
	if (p->format[p->idx2] == 'h' || p->format[p->idx2] == 'l' ||
			p->format[p->idx2] == 'j' || p->format[p->idx2] == 'z')
		ft_opt_modif(p);
	if (p->format[p->idx2] == '.')
		ft_opt_precision(p);
}

int			ft_opt(t_printf *p)
{
	if (p->format[p->idx2 + 1] == '%' || p->format[p->idx2] == '\0')
		return (1);
	while ((p->format[p->idx2] == '-' || p->format[p->idx2] == '+' ||
				p->format[p->idx2] == '#' || p->format[p->idx2] == '0' ||
				p->format[p->idx2] == ' ' || p->format[p->idx2] == 'h' ||
				p->format[p->idx2] == 'l' || p->format[p->idx2] == 'j' ||
				p->format[p->idx2] == 'z' || p->format[p->idx2] == '.' ||
				(ft_isdigit(p->format[p->idx2]))) && p->format[p->idx2] != '\0')
		ft_opt_specifier(p);
	return (1);
}
