/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okimdil <okimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:33:34 by okimdil           #+#    #+#             */
/*   Updated: 2019/11/19 19:33:36 by okimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printd_precision(t_flags flags, int *counter, int d)
{
	if (d >= 0)
	{
		g_spaces = flags.precision - ft_len(d);
		while (g_spaces-- > 0)
			ft_putchar('0', counter);
		ft_putnbr(d, counter);
	}
	else
	{
		d *= -1;
		g_spaces = flags.precision - ft_len(d);
		ft_putchar('-', counter);
		while (g_spaces-- > 0)
			ft_putchar('0', counter);
		ft_putnbr(d, counter);
	}
}

void	ft_printd_noprec(t_flags flags, int *counter, int d)
{
	if (d == 0 && flags.precision == 0)
	{
		g_spaces = flags.width;
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
	}
}

void	ft_printd_both(t_flags flags, int *counter, int d)
{
	if (d >= 0)
		ft_printud_both(d, flags, counter);
	else
		ft_printsd_both(d, flags, counter);
}

void	ft_printd(t_flags flags, va_list *args, int *counter)
{
	int	d;

	d = va_arg(*args, int);
	if (flags.is_flags == 0 || (flags.width <= ft_len(d)\
	&& flags.precision <= ft_len(d)))
	{
		if (d == 0 && flags.precision == 0)
			ft_printd_noprec(flags, counter, d);
		else
			ft_putnbr(d, counter);
		return ;
	}
	if (flags.width >= ft_len(d) && flags.precision > ft_len(d))
		ft_printd_both(flags, counter, d);
	if (flags.width >= ft_len(d) && flags.precision <= ft_len(d))
	{
		if (d == 0 && flags.precision == 0)
			ft_printd_noprec(flags, counter, d);
		else if (d >= 0)
			ft_printsd_width(d, flags, counter);
		else
			ft_printud_width(d, flags, counter);
	}
	if (flags.width < ft_len(d) && flags.precision > ft_len(d))
		ft_printd_precision(flags, counter, d);
}
