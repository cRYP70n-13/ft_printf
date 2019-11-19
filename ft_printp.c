/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okimdil <okimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:33:13 by okimdil           #+#    #+#             */
/*   Updated: 2019/11/19 19:33:15 by okimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_lenp(size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return ((i = 1));
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int		ft_printp_width(void *d, t_flags flags, int *counter)
{
	int	spaces;

	spaces = flags.width - ft_lenp((size_t)d) - 2;
	if (flags.dash == 0)
	{
		while (spaces-- > 0)
			ft_putchar(' ', counter);
		if (ft_putaddress(d, counter) == -1)
			return (-1);
	}
	else
	{
		if (ft_putaddress(d, counter) == -1)
			return (-1);
		while (spaces-- > 0)
			ft_putchar(' ', counter);
	}
	return (0);
}

void	ft_noprecision(t_flags flags, int *counter, int spaces)
{
	if (flags.width > 2)
	{
		spaces = flags.width - 2;
		if (flags.dash == 0)
		{
			while (spaces-- > 0)
				ft_putchar(' ', counter);
			ft_putstr("0x", counter);
		}
		else
		{
			ft_putstr("0x", counter);
			while (spaces-- > 0)
				ft_putchar(' ', counter);
		}
	}
	else
		ft_putstr("0x", counter);
}

int		ft_printp(t_flags flags, va_list *args, int *counter)
{
	void	*d;
	int		spaces;

	spaces = 0;
	d = va_arg(*args, char *);
	if (flags.precision == 0 && d == (void*)0)
	{
		ft_noprecision(flags, counter, spaces);
		return (0);
	}
	if (flags.is_flags == 0 || flags.width <= ft_lenp((size_t)d))
	{
		if (ft_putaddress(d, counter) == -1)
			return (-1);
	}
	if (flags.width > ft_lenp((size_t)d))
		ft_printp_width(d, flags, counter);
	return (0);
}
