# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fli <fli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 12:54:58 by fli               #+#    #+#              #
#    Updated: 2024/05/29 13:17:39 by fli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

INCLUDE = ./includes/

CFILES = ft_printf_bigx.c \
		 ft_printf_c.c \
		 ft_printf_d.c \
		 ft_printf_p.c \
		 ft_printf_s.c \
		 ft_printf_u.c \
		 ft_printf_x.c \
		 ft_printf.c \
		 ft_putnbr_base.c \
		 ft_putnbr_unsigned.c \
		 ft_putptr.c \

LIBFT = ./libft/

NAME = libftprintf.a

OBJ = $(CFILES:.c=.o)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	cp ./libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJ)

.c.o:
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
