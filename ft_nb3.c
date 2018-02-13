/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 21:12:32 by apoque            #+#    #+#             */
/*   Updated: 2018/02/13 22:11:04 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_umajint(t_printf *p)
{
	unsigned long	nb;

	nb = (unsigned int)va_arg(p->ap, long int);
	p->buf = ft_uitoa(nb);
	ft_buf(p);
}
