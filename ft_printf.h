/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okimdil <okimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:33:19 by okimdil           #+#    #+#             */
/*   Updated: 2019/11/19 22:02:16 by okimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# define BASES_UP "0123456789ABCDEF"
# define BASES_LOW "0123456789abcdef"

typedef struct	s_flags
{
	int	dash;
	int	zero;
	int	width;
	int	precision;
	int	is_flags;
}				t_flags;
int				g_spaces;
int				g_o;
int				ft_printf(const char *format, ...);
char			*ft_strchr(const char *s, int c);
int				ft_isdigit(int s);
void			ft_getflags(char *format, t_flags *flags,\
				va_list *args, int *i);
void			ft_printd(t_flags flags, va_list *args, int *counter);
int				ft_len(int a);
int				ft_lenu(unsigned int a);
int				ft_lenx(unsigned int n);
size_t			ft_slen(const char *str);
void			ft_printu(t_flags flags, va_list *args, int *counter);
void			ft_printud_both(int d, t_flags flags, int *counter);
void			ft_printsd_both(int d, t_flags flags, int *counter);
void			ft_printsd_width(int d, t_flags flags, int *counter);
void			ft_printud_width(int d, t_flags flags, int *counter);
int				ft_printp(t_flags flags, va_list *args, int *counter);
int				ft_printx(t_flags flags, va_list *args,\
				int *counter, int flag);
int				ft_printx_both(unsigned int d, t_flags flags,\
				int *counter, int flag);
void			ft_prints(t_flags flags, va_list *args, int *counter);
void			ft_prints_dash(int *counter, char *s, int p, int *i);
void			ft_prints_nodash(char *s, int *counter, int p, int *i);
void			ft_printc(t_flags flags, va_list *args, int *counter);
void			ft_print_perc(t_flags flags, int *counter);
int				hexlen(size_t n);
char			*convert(size_t num, int base, int flag);
void			ft_putchar(char c, int *counter);
void			ft_putstr(char *s, int *counter);
void			ft_putnbr(int nb, int *counter);
void			ft_put_unbr(unsigned int nb, int *counter);
int				ft_putaddress(void *ptr, int *counter);
#endif
