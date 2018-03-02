//HEADER
//
//
//
//
//
//
//
//


#include "printf.h"

void	ft_print_o2(t_printf *p, unsigned long u, int zeros)
{
	if ((p->flag[DIESE] == 1 && u != 0) || (p->flag[DIESE] == 1 && p->dot == 1))
	{
		ft_putchar('0');
		p->len++;
	}
	if (p->flag[MORE] == 1)
	{
		ft_putchar('+');
		p->len++;
	}
	if (p->size > 0 && p->flag[ZERO] == 1 && p->flag[LESS] != 1 && ((p->dot == 0 && p->flag[DIESE] != 1) || u == 0))
		ft_put_space(p, 1);
	if (zeros > 0)
		ft_put_precision(p, zeros);
	if (!(p->dot == 1 && u == 0))
		ft_buf(p);
	if (p->size > 0 && (p->flag[LESS] == 1))
		ft_put_space(p, 2);
}

void	ft_print_o(t_printf *p, unsigned long u)
{
	int	zeros;
	int	tmp;


	tmp = (p->flag[DIESE] == 1 && (u != 0 || p->dot == 1)) ? 1 : 0;
	zeros = p->precision - ft_strlen(p->buf) - tmp;
	zeros = (p->dot == 1 && u == 0) ? zeros + 1 : zeros;
	zeros = (zeros < 0) ? 0 : zeros;
	tmp = ((p->flag[DIESE] == 1 && (u != 0 || p->dot == 1)) && zeros == 0) ? 1 : 0;
	p->size = p->size - (zeros + ft_strlen(p->buf) + p->flag[MORE] + tmp);
	p->size = (p->dot == 1 && u == 0 && p->flag[DIESE] != 1) ? p->size + 1 : p->size;
	if (p->flag[SPACE] == 1 && p->flag[MORE] == 0)
		p->size--;
	if (p->size > 0 && ((p->flag[ZERO] != 1 || p->dot == 1 || (p->flag[DIESE] == 1 && p->flag[ZERO] != 1 && u == 0))) && p->flag[LESS] != 1)
		ft_put_space(p, 2);
	if (p->flag[SPACE] == 1 && p->flag[MORE] == 0)
	{
		ft_putchar(' ');
		p->len++;
	}
	ft_print_o2(p, u, zeros);
}

void	ft_oint(t_printf *p)
{
	unsigned int		o;
	unsigned long long	u;
	size_t				z;

	if (p->txt == 1)
		ft_buf(p);
	if (p->modif[Z] == 1)
	{
		z = va_arg(p->ap, size_t);
		p->buf = ft_itoabase_u(z, "01234567");
		ft_print_o(p, z);
	}
	else if (p->modif[J] == 1)
	{
		u = va_arg(p->ap, unsigned long long);
		p->buf = ft_itoabase_u(u, "01234567");
		ft_print_o(p, u);
	}
	else
	{
		o = va_arg(p->ap, unsigned int);
		p->buf = ft_itoabase_u(o, "01234567");
		ft_print_o(p, o);
	}

}

void		ft_omajint(t_printf *p)
{
	unsigned long	o;

	if (p->txt == 1)
		ft_buf(p);
	if (p->modif[L] == 1)
	o = (unsigned long int)va_arg(p->ap, unsigned long int);
	else
	o = (unsigned long long int)va_arg(p->ap, unsigned long long int);
	p->buf = ft_itoabase_u(o, "01234567");
	ft_print_o(p, o);
}

/*void	ft_oint(t_printf *p)
{
	unsigned int	nb;

	if (p->txt == 1)
		ft_buf(p);
	nb = (unsigned int)va_arg(p->ap, unsigned int);
	p->buf = ft_uitoabase(nb, 8);
	ft_buf(p);
}

void	ft_omajint(t_printf *p)
{
	long int	nb;

	if (p->txt == 1)
		ft_buf(p);
	nb = va_arg(p->ap, long int);
	p->buf = ft_litoabase(nb, 8);
	ft_buf(p);
}*/
