/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:06:12 by apoque            #+#    #+#             */
/*   Updated: 2018/02/13 22:18:29 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"
#include <limits.h>

int		main(void)
{
	unsigned int		i;
	void	*p;
	wchar_t	*str;
	wchar_t	c;

	i = 0;
	p = &i;
	str = L"Привет";
	c = 256;

	printf("[%d]\n", printf("%20.ld et %.4hhi !", 0x11ffaa147, (signed char)-89));
	printf("{%d}\n", ft_printf("%20.ld et %.4hhi !", 0x11ffaa147, (signed char)-89));
	//printf("%ls\n", str);
	//ft_printf("%S\n", str);
	return (i);
}
