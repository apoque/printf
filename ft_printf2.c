/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 21:14:51 by apoque            #+#    #+#             */
/*   Updated: 2018/02/13 22:32:27 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_treatment2(t_printf *p)
{
	int	a;

	a = 1;
	if (p->format[p->idx2] == 'S')
			ft_wstr(p);
	else if (p->format[p->idx2] == 'c')
			ft_char(p);
	else if (p->format[p->idx2] == 'U')
		ft_umajint(p);
	else if (p->format[p->idx2] == 'C')
			ft_wchar(p);
	else
		a = 0;
	if (a == 1)
		p->idx2++;
}
