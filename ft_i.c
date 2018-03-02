/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 20:35:31 by apoque            #+#    #+#             */
/*   Updated: 2018/02/13 20:49:18 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

#define R (result % 10) + 48

int	ft_string_size(long long n, int signe)
{
	int	size;

	size = 1 + signe;
	if (n > 0)
	{
		while (n / 10 > 0)
		{
			n = n / 10;
			size++;
		}
	}
	else if (n < 0)
	{
		while (n / 10 < 0)
		{
			n = n / 10;
			size++;
		}
	}
	return (size);
}

char		*ft_ltoa(long n)
{
	long long	result;
	char		*str;
	int			signe;
	int			size;
	int			i;

	signe = 0;
	i = 0;
	result = (long long)n;
	if (result < 0)
		signe = 1;
	if (result < 0)
		result = -result;
	size = ft_string_size(result, signe);
	if (!(str = ft_strnew(size)))
		return (NULL);
	if (signe == 1)
		str[0] = '-';
	while (i < size - signe)
	{
		(result > 0) ? str[size - 1 - i] = R : (str[size - 1 - i] = -R);
		result = result / 10;
		i++;
	}
	return (str);
}

void	ft_int2(t_printf *p, int i, int zeros)
{
	if (p->flag[MORE] == 1 && i >= 0)
	{
		ft_putchar('+');
		p->len++;
	}
	if (i < 0 && i != INT_MIN)
	{
		ft_putchar('-');
		p->len++;
		i = -i;
	}
	if (p->size > 0 && (p->flag[ZERO] == 1 && p->precision == 0) && p->flag[LESS] != 1)
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

void	ft_int(t_printf *p)
{
	int			i;
	int			tmp;
	int			zeros;
	char		*str;

	if (p->txt == 1)
		ft_buf(p);
	i = va_arg(p->ap, int);
	str = ft_itoa((tmp = (i < 0) ? -i : i ));
	zeros = p->precision - ft_strlen(str);
	zeros = (p->dot == 1 && i == 0) ? zeros + 1 : zeros;
	zeros = (zeros < 0) ? 0 : zeros;
	free(str);
	str = ft_itoa(i);
	p->size = p->size - (zeros + ft_strlen(str) + (tmp = (p->flag[MORE] == 1 && i >= 0) ? 1 : 0));
	free(str);
	p->size = (p->dot == 1 && i == 0) ? p->size + 1 : p->size;
	if (p->flag[SPACE] == 1 && i >= 0 && p->flag[MORE] == 0)
		p->size--;
	if (p->size > 0 && (p->flag[ZERO] != 1 || p->precision > 0) && p->flag[LESS] != 1)
		ft_put_space(p, 2);
	if (p->flag[SPACE] == 1 && i >= 0 && p->flag[MORE] == 0)
	{
		ft_putchar(' ');
		p->len++;
	}
	if (p->modif[H] == 1)
		ft_int2(p, (short int)i, zeros);
	else if (p->modif[HH] == 1)
		ft_int2(p, (signed char)i, zeros);
	else
		ft_int2(p, i, zeros);
}
