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
	if (c >= 0 && c <= 0x7F)
		return (1);
	else if (c >= 0x80 && c <= 0x7FF)
		return (2);
	else if ((c >= 0x800 && c <= 0xD7FF) || (c >= 0xE000 && c <= 0xFFFF))
		return (3);
	else if (c >= 0x10000 && c <= 0x10FFFF)
		return (4);
	else
		return (-1);
}

/*int		ft_wstr_len(wchar_t *str)
  {
  int	len;
  int	i;

  i = 0;
  len = 0;
//printf("str= %ls\n<i = %d, len = %d>\n", str, i, len);
while (str[i])
{
len = len + ft_wchar_len(str[i]);
//printf("<i = %d, len = %d\n", i, ft_wchar_len(str[i]));
i++;
}
return (len);
}*/

int		calc_wstrlen(wchar_t *str, int precision, int i)
{
	if (*str == '\0' || precision == 0)
		return (i);
	else if (*str <= 0x7F)
		return (calc_wstrlen(str + 1, precision - 1, i + 1));
	else if (*str <= 0x7FF && precision >= 2)
		return (calc_wstrlen(str + 1, precision - 2, i + 2));
	else if (*str <= 0xFFFF && precision >= 3)
		return (calc_wstrlen(str + 1, precision - 3, i + 3));
	else if (*str <= 0x10FFFF && precision >= 4)
		return (calc_wstrlen(str + 1, precision - 4, i + 4));
	else
		return (i);
}

void	ft_get_lens(t_printf *p, wchar_t *str, int *len_without_error, int *len_precision)
{
	int	j;
	int	i;
	int	a;
	int	error;

	j = 0;
	i = -1;
	a = 0;
	error = 0;
	while (j < ft_wstrlen(str))
	{
		error = (str[++i] > 0x10ffff || (str[i] >= 0xd800 && str[i] <= 0xdfff) || str[i] < 0) ? -1 : error;
		a = ft_get_a(str[i]);
		error = ((MB_CUR_MAX == 1 && a > 8) || (MB_CUR_MAX == 2 && a > 11) || (MB_CUR_MAX == 3 && a > 16) || (MB_CUR_MAX == 4 && a > 21)) ? -1 : error;
		j = ft_char_size(a, j);
		*len_without_error = (error == 0) ? j : *len_without_error;
	}
	i = -1;
	while (++i < p->precision)
	{
		a = ft_get_a(str[i]);
		*len_precision = ft_char_size(a, *len_precision);
	}
}

void	ft_wstr2(t_printf *p, wchar_t *str)
{
	int	i;
	int	len_without_error;
	int	len_precision;

	i = 0;
	len_without_error = 0;
	len_precision = 0;
	if (p->buf == NULL)
		p->buf = ft_strdup("(null)");
	if (p->error == -1 && p->dot == 1 && p->precision > 0)
		ft_get_lens(p, str, &len_without_error, &len_precision);
	if (p->error != -1 || ((len_without_error >= len_precision) && p->dot == 1))
	{
		i = (p->dot == 1 && p->precision < ft_wstrlen(str)) ? calc_wstrlen(str, p->precision, 0) : ft_wstrlen(str);
		p->buf = ft_strndup(p->buf, i);
		p->error = 0;
		p->size = p->size - ft_strlen(p->buf);
		if (p->size > 0 && p->flag[LESS] == 0)
			ft_put_space(p, 2);
		ft_buf(p);
		if (p->size > 0 && p->flag[LESS] == 1)
			ft_put_space(p, 2);
	}
}

void	ft_wstr(t_printf *p)
{
	int i;
	wchar_t	*str;
	char	buf[5];

	ft_buf(p);
	i = 0;
	str = va_arg(p->ap, wchar_t *);
	while (str[i] != L'\0')
	{
		ft_bzero(buf, 5);
		ft_conv_wchar(p, str[i], buf);
		i++;
		p->buf = ft_strjoin(p->buf, buf);
	}
	ft_wstr2(p, str);
}

void	ft_str(t_printf *p)
{
	char	*str;
	int		len;

	len = -1;
	ft_buf(p);
	if (p->dot == 1)
		len = p->precision;
	str = va_arg(p->ap, char *);
	if (str == NULL)
		str = "(null)";
	if (len == -1)
		p->buf = ft_strdup(str);
	else
		p->buf = ft_strndup(str, len);
	p->size = p->size - ft_strlen(p->buf);
	if (p->size > 0 && p->flag[LESS] == 0)
		ft_put_space(p, 2);
	ft_buf(p);
	if (p->size > 0 && p->flag[LESS] == 1)
		ft_put_space(p, 2);
}
