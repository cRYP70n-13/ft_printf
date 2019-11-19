# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okimdil <okimdil@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 19:34:55 by okimdil           #+#    #+#              #
#    Updated: 2019/11/19 22:02:45 by okimdil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_printf_utils.c ft_convert.c ft_getflags.c ft_isdigit.c \
ft_printd.c ft_strchr.c ft_printu.c ft_printp.c ft_printx.c ft_prints.c \
ft_printc.c ft_print_perc.c ft_len.c ft_printd_utils.c ft_lenu.c ft_lenx.c \
ft_slen.c ft_prints_dash.c ft_printx_both.c

OBJ = $(SRC:.c=.o)
 
all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus