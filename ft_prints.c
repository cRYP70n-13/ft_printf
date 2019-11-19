/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okimdil <okimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:33:01 by okimdil           #+#    #+#             */
/*   Updated: 2019/11/19 19:33:03 by okimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prints_both(char *s, t_flags flags, int *counter)
{
	int	p;
	int	i;

	i = 0;
	p = flags.precision;
	if (flags.precision >= (int)ft_slen(s))
		g_spaces = flags.width - (int)ft_slen(s);
	else
		g_spaces = flags.width - flags.precision;
	if (flags.dash == 0)
		ft_prints_dash(counter, s, p, &i);
	else
	{
		while (p-- > 0 && s[i] != '\0')
		{
			ft_putchar(s[i], counter);
			i++;
		}
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
	}
}

void	ft_prints_width(char *s, t_flags flags, int *counter)
{
	g_spaces = flags.width - (int)ft_slen(s);
	if (flags.dash == 0)
	{
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
		ft_putstr(s, counter);
	}
	else
	{
		ft_putstr(s, counter);
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
	}
}

void	ft_prints_prec(char *s, t_flags flags, int *counter)
{
	int	p;
	int	i;

	i = 0;
	g_spaces = flags.width - flags.precision;
	p = flags.precision;
	if (flags.precision == 0)
	{
		g_spaces = flags.width;
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
	}
	else
	{
		if (flags.dash == 0)
			ft_prints_dash(counter, s, p, &i);
		else
			ft_prints_nodash(s, counter, p, &i);
	}
}

void	ft_prints(t_flags flags, va_list *args, int *counter)
{
	char	*s;
	int		size_s;

	s = va_arg(*args, char *);
	if (s == NULL)
		s = "(null)";
	size_s = (int)ft_slen(s);
	if (flags.is_flags == 0 || (flags.width <= size_s \
	&& (flags.precision >= size_s || flags.precision == -1)))
	{
		ft_putstr(s, counter);
		return ;
	}
	if (flags.width >= size_s && (flags.precision < size_s\
	&& flags.precision >= 0))
		ft_prints_both(s, flags, counter);
	if (flags.width >= size_s && (flags.precision >= size_s\
	|| flags.precision == -1))
		ft_prints_width(s, flags, counter);
	if (flags.width < size_s && (flags.precision < size_s\
	&& flags.precision >= 0))
		ft_prints_prec(s, flags, counter);
}
