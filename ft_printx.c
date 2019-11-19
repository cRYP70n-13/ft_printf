/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okimdil <okimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:32:23 by okimdil           #+#    #+#             */
/*   Updated: 2019/11/19 22:05:33 by okimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	g_d;
int				g_spaces;
int				g_o;

int		ft_printx_width(unsigned int d, t_flags flags, int *counter, int flag)
{
	char	*tmp;

	if ((tmp = convert(d, 16, flag)) == NULL)
		return (-1);
	g_spaces = flags.width - ft_lenx(d);
	if (flags.dash == 0)
	{
		while (g_spaces-- > 0)
		{
			if (flags.zero == 1)
				ft_putchar('0', counter);
			else
				ft_putchar(' ', counter);
		}
		ft_putstr(tmp, counter);
	}
	else
	{
		ft_putstr(tmp, counter);
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
	}
	free(tmp);
	return (0);
}

void	ft_printxz_precz(t_flags flags, int *counter)
{
	g_spaces = flags.width;
	while (g_spaces-- > 0)
		ft_putchar(' ', counter);
}

void	ft_printx_prec(t_flags flags, int *counter, unsigned int d, char *tmp)
{
	g_spaces = flags.precision - ft_lenx(d);
	while (g_spaces-- > 0)
		ft_putchar('0', counter);
	ft_putstr(tmp, counter);
	free(tmp);
}

void	ft_printx_precz(t_flags flags, int *counter, char *tmp)
{
	if (g_d == 0 && flags.precision == 0)
		ft_printxz_precz(flags, counter);
	else
		ft_putstr(tmp, counter);
	free(tmp);
}

int		ft_printx(t_flags flags, va_list *args, int *counter, int flag)
{
	char			*tmp;

	g_d = va_arg(*args, unsigned int);
	if ((tmp = convert(g_d, 16, flag)) == NULL)
		return (-1);
	if (flags.is_flags == 0 || (flags.width <= ft_lenx(g_d)\
	&& flags.precision <= ft_lenx(g_d)))
		ft_printx_precz(flags, counter, tmp);
	else if (flags.width >= ft_lenx(g_d) && flags.precision > ft_lenx(g_d))
		ft_printx_both(g_d, flags, counter, flag);
	else if (flags.width >= ft_lenx(g_d) && flags.precision <= ft_lenx(g_d))
	{
		if (g_d == 0 && flags.precision == 0)
			ft_printxz_precz(flags, counter);
		else
			ft_printx_width(g_d, flags, counter, flag);
	}
	else if (flags.width < ft_lenx(g_d) && flags.precision > ft_lenx(g_d))
		ft_printx_prec(flags, counter, g_d, tmp);
	return (0);
}
