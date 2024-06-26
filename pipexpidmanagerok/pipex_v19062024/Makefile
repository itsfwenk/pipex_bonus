# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fli <fli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 16:42:15 by fli               #+#    #+#              #
#    Updated: 2024/06/19 17:13:47 by fli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

INCLUDE = ./includes/

CFILES = cmd_exec.c \
		 ft_strjoin_pipex.c \
		 pipex.c \
		 pipex_utils.c\


LIBFT = ./libft/

NAME = pipex

LIB = library.a

OBJ = $(CFILES:.c=.o)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

$(LIB):
	make -C $(LIBFT)
	cp ./libft/libft.a $(LIB)

.c.o:
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
