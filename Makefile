# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olaktion <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/10 15:47:56 by olaktion          #+#    #+#              #
#    Updated: 2018/02/19 17:58:49 by rhrab            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fillit
SRC =	./src/main.c \
		./src/valid.c \
		./src/valid2.c \
		./src/alloc.c \
		./src/solv.c \
		./src/solv2.c \
		./src/ft_memdel.c \
		./src/ft_putchar.c \
		./src/ft_putstr.c \
		./src/ft_strlen.c \
		./src/ft_strnew.c \
		./src/square_tool.c

OBJ =	$(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ gcc $(OBJ) $(CFLAGS) -o $(NAME)

%.o: %.c
	@ gcc $(CFLAGS) -c $< -o $@

clean:
	@ /bin/rm -rf $(OBJ)

fclean: clean
	@ /bin/rm -f $(NAME)

re: fclean all

.NOTPARALLEL: all clean fclean re
.PHONY: all clean fclean re
