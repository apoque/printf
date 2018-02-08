//HEADER

#include "printf.h"

void	ft_str(t_printf *p)
{
	p->add = ft_strdup(va_arg(p->ap, char *));
	ft_buf(p);
}
