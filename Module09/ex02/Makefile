# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/18 09:23:58 by yasmine           #+#    #+#              #
#    Updated: 2026/07/19 07:09:28 by yasmine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pmergeme
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp PmergeMe.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
