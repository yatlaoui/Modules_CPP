# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 20:20:10 by yasmine           #+#    #+#              #
#    Updated: 2025/12/17 11:30:23 by yasmine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = my_awesome_phonebook
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp Contact_class.cpp PhoneBook_class.cpp
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