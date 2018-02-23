/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:28:37 by apoque            #+#    #+#             */
/*   Updated: 2018/02/13 17:28:43 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_wchar_len(wchar_t c)
{
	if (c < 0x80)
		return (1);
	else if (c < 0x800)
		return (2);
	else if (c < 0x10000)
		return (3);
	else
		return (4);
}

int		ft_wstr_len(wchar_t *str)
{
	int	len;

	len = 0;
	while (*str != L'\0')
	{
		len = len + ft_wchar_len(*str);
		str++;
	}
	return (len);
}

void	ft_wstr(t_printf *p)
{
	wchar_t *str;

	ft_buf(p);
	str = va_arg(p->ap, wchar_t *);
	while (*str != L'\0')
	{
		ft_putwchar(*str);
		str++;
		p->len++;
	}
}

void	ft_str(t_printf *p)
{
	ft_buf(p);
	p->buf = ft_strdup(va_arg(p->ap, char *));
	ft_buf(p);
}
