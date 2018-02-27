//HEADER
//
//
//
//
//
//
//

#include "printf.h"


void	ft_p(t_printf *p)
{
	unsigned long	point;

	if (p->txt == 1)
		ft_buf(p);
	point = (unsigned long)va_arg(p->ap, void *);
	p->buf = ft_itoabase_u(point, "0123456789abcdef");
	p->size = p->size - ft_strlen(p->buf) - 2;
	p->flag[DIESE] = 1;
	p->flag[J] = -5;
	ft_print_x2(p, point, 0);
}
