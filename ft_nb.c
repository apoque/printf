/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 20:35:31 by apoque            #+#    #+#             */
/*   Updated: 2018/02/13 19:37:13 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

#define R (result % 10) + 48

static int	ft_string_size(long long n, int signe)
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

char		*ft_uitoa(unsigned int n)
{
	long long	result;
	char		*str;
	int			signe;
	int			size;
	int			i;

	signe = 0;
	i = 0;
	result = (unsigned long)n;
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

void	ft_long(t_printf *p)
{
	p->buf = ft_ltoa(va_arg(p->ap, long));
	ft_buf(p);
}

void	ft_int(t_printf *p)
{
	p->buf = ft_itoa(va_arg(p->ap, int));
	ft_buf(p);
}
