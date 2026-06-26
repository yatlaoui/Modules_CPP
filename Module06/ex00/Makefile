# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/26 19:08:44 by yasmine           #+#    #+#              #
#    Updated: 2026/06/26 19:11:23 by yasmine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scalarconverter
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp ScalarConverter.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re