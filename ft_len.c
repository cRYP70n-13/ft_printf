/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okimdil <okimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:34:06 by okimdil           #+#    #+#             */
/*   Updated: 2019/11/19 19:34:08 by okimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_len(int a)
{
	int	i;

	i = 0;
	if (a == 0)
		return (1);
	if (a == -2147483648)
		return (10);
	if (a < 0)
	{
		a *= -1;
		while (a > 0)
		{
			a /= 10;
			i++;
		}
	}
	while (a > 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}
