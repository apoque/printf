//HEADER

#include "printf.h"

void	ft_putwchar(wchar_t chr)
{
	if (chr <= 0x7F)
		ft_putchar(chr);
	else if (chr <= 0x7FF)
	{
		ft_putchar((chr >> 6) | 0xC0);
		ft_putchar((chr & 0x3F) | 0x80);
	}
	else if (chr <= 0xFFFF)
	{
		ft_putchar((chr >> 12) | 0xE0);
		ft_putchar((chr >> 6) | 0xC0);
		ft_putchar((chr & 0x3F) | 0x80);
	}
	else if (chr <= 0x10FFFF)
	{
		ft_putchar((chr >> 18) | 0xF0);
		ft_putchar(((chr >> 12) & 0x3F) | 0x80);
		ft_putchar(((chr >> 6) & 0x3F) | 0x80);
		ft_putchar((chr & 0x3F) | 0x80);
	}
}

void	ft_wchar(t_printf *p)
{
	wint_t	c;

	c = va_arg(p->ap, wint_t);
	ft_putwchar(c);
	p->len = p->len + ft_wchar_len(c);
}

void	ft_char(t_printf *p)
{
	int c;

	c = va_arg(p->ap, int);
	if (p->size-- > 0 && p->flag[LESS] == 0)
		ft_put_space(p, 2);
	ft_putchar(c);
	p->len++;
	if (p->size > 0 && p->flag[LESS] == 1)
		ft_put_space(p, 2);
}
