//HEADER

#include "printf.h"

void	ft_char(t_printf *p)
{
	int c;
	char *str;

	c = va_arg(p->ap, int);
	str = (char *)malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	p->add = ft_strdup(str);
	free(str);
	ft_buf(p);
}
