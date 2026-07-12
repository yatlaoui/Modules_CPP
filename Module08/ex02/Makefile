# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/12 03:00:03 by yasmine           #+#    #+#              #
#    Updated: 2026/07/12 03:02:24 by yasmine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mutantstack
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp MutantStack.cpp
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
