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
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>




int		main(void)
{
	unsigned int		i;
	void	*p;
	wchar_t	str[4];
	wchar_t	c;
	wchar_t *s;

	setlocale(LC_ALL, "");
	//printf("%i\n", MB_CUR_MAX);
	i = 0;
	p = &i;
	s = L"S„™ºÚÅÄÄS„";
	str[0] = 'S';
	str[1] = 254;
	str[2] = 'u';
	str[3] = '\0';
	//str = L"S˛";
	c = L'˛';

	printf("[%d]\n", printf("{%C}", 0));
	printf("{%d}\n", ft_printf("{% C}", 0));
	//printf("%ls\n", str);
	//ft_printf("%S\n", str);
	//while (1)
	;
	return (i);
}
