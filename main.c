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
	int	i;

	i = 9;
	//printf("printf = \n|");
	printf("\nnb = %d\n\n", printf("%d", i));
	//printf("\n\nft_printf = \n|");
	printf("\nnb = %d\n", ft_printf("%d", i));
	//printf("|\n");
	//
	//printf("Salut\n\n");
	//ft_printf("Salut\n");

	return (1);
}
