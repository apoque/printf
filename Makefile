# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apoque <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 15:03:55 by apoque            #+#    #+#              #
#    Updated: 2018/02/13 21:15:00 by apoque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wextra -Wall

NAME = printf

INC = printf.h

SRC =main.c \
	 ft_printf.c\
	 ft_printf2.c\
	 ft_printf3.c\
	 ft_nb.c\
	 ft_nb2.c\
	 ft_nb3.c\
	 ft_str.c\
	 ft_char.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	#cp libft/libft.a ./libftprintf.a
	#cd libft ; make ; cd ..
	$(CC) $(FLAGS) $(OBJ) -I/$(INC) libft/libft.a -o $(NAME)
	ar -rc temp.a $(OBJ)
	libtool -static -o libftprintf.a temp.a libft/libft.a
	ranlib libftprintf.a
	rm temp.a

clean :
	cd libft ; make fclean ; cd ..
	rm $(OBJ)

fclean : clean
	rm  $(NAME) 
	rm libftprintf.a

re : fclean all

.PHONY: all clean fclean re
