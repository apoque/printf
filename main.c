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
	wchar_t	*str;
	wchar_t	c;

	setlocale(LC_ALL, "en_US.UTF-8");
	i = 0;
	p = &i;
	/*str[0] = 'S';
	str[1] = 254;
	str[2] = 'u';
	str[3] = '\0';*/
	str = L"S˛";
	c = L'˛';

	printf("[%d]\n", printf("%#-8.3o\n", 0));
	printf("{%d}\n", ft_printf("%#-8.3o\n", 0));
	//printf("%ls\n", str);
	//ft_printf("%S\n", str);
	return (i);
}
