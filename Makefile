# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngmki <youngmki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 19:55:35 by youngmki          #+#    #+#              #
#    Updated: 2021/09/23 21:53:52 by youngmki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS_PATH = srcs/
SRCS_OBJS = $(SRCS:.c=.o)
SRCS = \
	./ft_eval_format.c \
	./ft_interface.c \
	./ft_printf.c \
	./ft_proc_addr.c \
	./ft_proc_char.c \
	./ft_proc_signed.c \
	./ft_proc_unsigned.c \
	./ft_proc_hex_l.c \
	./ft_proc_hex_u.c \
	./ft_proc_percent.c \
	./ft_proc_string.c \

.PHONY: all clean fclean re bonus

$(NAME): $(SRCS_OBJS)
	ar -crs $(NAME) $(SRCS_OBJS)

all: $(NAME)

clean:
	rm -f $(SRCS_OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

bonus: all