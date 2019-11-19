/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okimdil <okimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:34:33 by okimdil           #+#    #+#             */
/*   Updated: 2019/11/19 19:34:35 by okimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_width(char *ptr, int *i)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while ((ptr[*i] >= 9 && ptr[*i] <= 13) || ptr[*i] == ' ')
		(*i)++;
	if (ptr[*i] == '+' || ptr[*i] == '-')
	{
		if (ptr[*i] == '-')
			sign = -1;
		(*i)++;
	}
	while (ptr[*i] && ptr[*i] >= '0' && ptr[*i] <= '9')
	{
		res = res * 10 + (ptr[*i] - '0');
		(*i)++;
	}
	return (res * sign);
}

void	ft_get_precision(char *format, t_flags *flags, va_list *args, int *i)
{
	(*i)++;
	if (!ft_isdigit(format[*i]) && format[*i] != '*')
	{
		flags->precision = 0;
		(*i)--;
	}
	if (ft_isdigit(format[*i]) || format[*i] == '-')
		flags->precision = ft_width(format, i);
	else if (format[(*i)++] == '*')
	{
		flags->precision = va_arg(*args, int);
		if (flags->precision < 0)
			flags->precision = -1;
	}
}

void	ft_get_width_star(t_flags *flags, va_list *args, int *i)
{
	(*i)++;
	flags->width = va_arg(*args, int);
	if (flags->width < 0)
	{
		flags->dash = 1;
		flags->width *= -1;
	}
}

void	ft_getflags(char *format, t_flags *flags, va_list *args, int *i)
{
	while (ft_strchr("cspduixX%", format[*i]) == NULL)
	{
		if (format[*i] == '-')
		{
			flags->dash = 1;
			(*i)++;
		}
		if (format[*i] == '0')
		{
			flags->zero = 1;
			(*i)++;
		}
		if (ft_isdigit(format[*i]))
			flags->width = ft_width(format, i);
		else if (format[*i] == '*')
			ft_get_width_star(flags, args, i);
		if (format[*i] == '.')
		{
			ft_get_precision(format, flags, args, i);
		}
	}
	if (flags->dash != 0 || flags->zero != 0 \
	|| flags->width > 0 || flags->precision >= 0)
		flags->is_flags = 1;
}
