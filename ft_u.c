//HEADER
//
//
//
//
//
//
//
//
//
//


#include "printf.h"

void	ft_print_u2(t_printf *p, unsigned long u, int zeros)
{
	if (p->flag[MORE] == 1)
	{
		ft_putchar('+');
		p->len++;
	}
	if (p->size > 0 && (p->flag[ZERO] == 1 && p->precision == 0))
		ft_put_space(p, 1);
	if (zeros > 0)
		ft_put_precision(p, zeros);
	if (!(p->dot == 1 && u == 0))
		ft_buf(p);
	if (p->size > 0 && (p->flag[LESS] == 1))
		ft_put_space(p, 2);
}

void	ft_print_u(t_printf *p, unsigned long u)
{
	int	zeros;

	zeros = p->precision - ft_strlen(p->buf);
	zeros = (p->dot == 1 && u == 0) ? zeros + 1 : zeros;
	zeros = (zeros < 0) ? 0 : zeros;
	p->size = p->size - (zeros + ft_strlen(p->buf) + p->flag[MORE]);
	p->size = (p->dot == 1 && u == 0) ? p->size + 1 : p->size;
	if (p->flag[SPACE] == 1 && p->flag[MORE] == 0)
		p->size--;
	if (p->size > 0 && (p->flag[ZERO] != 1 || p->precision > 0) && p->flag[LESS] != 1)
		ft_put_space(p, 2);
	if (p->flag[SPACE] == 1 && p->flag[MORE] == 0)
	{
		ft_putchar(' ');
		p->len++;
	}
	ft_print_u2(p, u, zeros);
}

void	ft_uint(t_printf *p)
{
	unsigned int	u;
	size_t			z;

	if (p->txt == 1)
		ft_buf(p);
	if (p->modif[Z] == 1)
	{
		z = va_arg(p->ap, size_t);
		p->buf = ft_itoabase_u(z, "0123456789");
		ft_print_u(p, z);
	}
	else
	{
		u = va_arg(p->ap, unsigned int);
		p->buf = ft_itoabase_u(u, "0123456789");
		ft_print_u(p, u);
	}

}

void		ft_umajint(t_printf *p)
{
	unsigned long	u;

	if (p->txt == 1)
		ft_buf(p);
	if (p->modif[L] == 1)
	u = (unsigned long int)va_arg(p->ap, unsigned long int);
	else
	u = (unsigned long long int)va_arg(p->ap, unsigned long long int);
	p->buf = ft_itoabase_u(u, "0123456789");
	ft_print_u(p, u);
}
