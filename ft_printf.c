/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okimdil <okimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:31:58 by okimdil           #+#    #+#             */
/*   Updated: 2019/11/19 22:03:37 by okimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	g_flags;

void	flags_init(t_flags *flags)
{
	flags->dash = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->is_flags = 0;
}

int		ft_check_format(char *format, int *i, int *count, va_list *args)
{
	if (format[*i] == 'd' || format[*i] == 'i')
		ft_printd(g_flags, args, count);
	else if (format[*i] == 'u')
		ft_printu(g_flags, args, count);
	else if (format[*i] == 'p')
	{
		if (ft_printp(g_flags, args, count) == -1)
			return (-1);
	}
	else if (format[*i] == 'X')
		ft_printx(g_flags, args, count, 1);
	else if (format[*i] == 'x')
	{
		if (ft_printx(g_flags, args, count, 0) == -1)
			return (-1);
	}
	else if (format[*i] == 's')
		ft_prints(g_flags, args, count);
	else if (format[*i] == 'c')
		ft_printc(g_flags, args, count);
	else if (format[*i] == '%')
		ft_print_perc(g_flags, count);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		flags_init(&g_flags);
		while (format[i] != '%' && format[i] != '\0')
		{
			ft_putchar(format[i], &count);
			i++;
		}
		if (format[i] != '\0')
			i++;
		ft_getflags((char *)format, &g_flags, &args, &i);
		ft_check_format((char *)format, &i, &count, &args);
		if (format[i] != '\0')
			i++;
	}
	va_end(args);
	return (count);
}
