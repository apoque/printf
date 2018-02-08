# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apoque <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 15:03:55 by apoque            #+#    #+#              #
#    Updated: 2018/01/23 21:07:41 by apoque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

//CFLAGS = -Werror -Wextra -Wall

NAME = printf

INC = printf.h

SRC =main.c \
	 ft_printf.c\
	 ft_nb.c\
	 ft_str.c\
	 ft_char.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	cd libft ; make ; cd ..
	$(CC) $(FLAGS) $(OBJ) -I/$(INC) libft/libft.a -o $(NAME)

clean :
	cd libft ; make fclean ; cd ..
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
