/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:06:12 by apoque            #+#    #+#             */
/*   Updated: 2018/01/15 16:01:22 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int		main(void)
{
	printf("printf = \n|");
	printf("Hello word !\n");
	printf("|\nft_printf = \n|");
	ft_printf("Hello word !\n");
	printf("|\n");

	return (1);
}
