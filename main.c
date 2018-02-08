/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:06:12 by apoque            #+#    #+#             */
/*   Updated: 2018/01/23 21:10:05 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int		main(void)
{
	int		i;
	char	*str;
	char	c;

	i = 69;
	str = "suce ma\n";
	c = 'P';

	printf("Yo_%i_Yi%i\n%s%c\n", i, i, str, c);
	ft_printf("Yo_%i_Yi%i\n%s%c\n", i, i, str, c);
	return (i);
}
