/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okimdil <okimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:34:01 by okimdil           #+#    #+#             */
/*   Updated: 2019/11/19 19:34:03 by okimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_lenu(unsigned int a)
{
	int	i;

	i = 0;
	if (a == 0)
		return (1);
	while (a > 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}
