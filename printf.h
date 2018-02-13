/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:04:39 by apoque            #+#    #+#             */
/*   Updated: 2018/02/13 21:17:48 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
#include "libft/libft.h"

# include <stdio.h>

typedef struct				s_printf
{
	const char			*format;
	va_list				ap;
	int					len;
	int					idx1;
	int					idx2;
	char				*buf;
}							t_printf;

int						ft_printf(const char *, ...);
char					*ft_uitoa(unsigned int n);
void					ft_putwchar(wchar_t chr);
void					ft_int(t_printf *p);
void					ft_uint(t_printf *p);
void					ft_umajint(t_printf *p);
void					ft_xint(t_printf *p);
void					ft_xmajint(t_printf *p);
void					ft_oint(t_printf *p);
void					ft_omajint(t_printf *p);
void					ft_long(t_printf *p);
void					ft_pointer(t_printf *p);
void					ft_str(t_printf *p);
void					ft_wstr(t_printf *p);
void					ft_char(t_printf *p);
void					ft_wchar(t_printf *p);
void					ft_init_p(t_printf *p, const char *format);
void					ft_buf(t_printf *p);
void					ft_treatment2(t_printf *p);

#endif
