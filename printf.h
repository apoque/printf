/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:04:39 by apoque            #+#    #+#             */
/*   Updated: 2018/01/23 21:10:09 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
#include "libft/libft.h"

typedef struct		s_printf
{
	const char		*format;
	va_list			ap;
	int				conv;
	int				size;
	int				idx;
}					t_printf;

int					ft_printf(const char *, ...);
void				ft_init_ap(va_list *ap);
t_printf			ft_nb(t_printf p);
void				ft_init_p(t_printf *p, const char *format);

#endif
