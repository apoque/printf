//HEADER

#include "printf.h"

void	ft_putwchar(wchar_t chr)
{
	if (chr <= 0x7F)
		ft_putchar(chr);
	else if (chr <= 0x7FF)
	{
		ft_putchar((chr >> 6) + 0xC0);
		ft_putchar((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0xFFFF)
	{
		ft_putchar((chr >> 12) + 0xE0);
		ft_putchar((chr >> 6) + 0xC0);
		ft_putchar((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0x10FFFF)
	{
		ft_putchar((chr >> 18) + 0xF0);
		ft_putchar(((chr >> 12) & 0x3F) + 0x80);
		ft_putchar(((chr >> 6) & 0x3F) + 0x80);
		ft_putchar((chr & 0x3F) + 0x80);
	}
}

void	ft_wchar(t_printf *p)
{
	ft_putwchar(va_arg(p->ap, wchar_t));
	p->len++;
}

void	ft_char(t_printf *p)
{
	int c;
	char *str;

	c = va_arg(p->ap, int);
	str = (char *)malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	p->buf = ft_strdup(str);
	free(str);
	ft_buf(p);
}
