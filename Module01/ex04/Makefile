# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 17:45:27 by yasmine           #+#    #+#              #
#    Updated: 2025/12/16 17:45:28 by yasmine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sed_is_for_losers
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRC = FileReplacer.cpp main.cpp
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
