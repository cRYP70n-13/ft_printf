/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints_dash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okimdil <okimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:33:07 by okimdil           #+#    #+#             */
/*   Updated: 2019/11/19 19:33:09 by okimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prints_dash(int *counter, char *s, int p, int *i)
{
	while (g_spaces-- > 0)
		ft_putchar(' ', counter);
	while (p-- > 0 && s[*i] != '\0')
	{
		ft_putchar(s[*i], counter);
		(*i)++;
	}
}

void	ft_prints_nodash(char *s, int *counter, int p, int *i)
{
	while (p-- > 0 && s[*i] != '\0')
	{
		ft_putchar(s[*i], counter);
		(*i)++;
	}
	while (g_spaces-- > 0)
		ft_putchar(' ', counter);
}
