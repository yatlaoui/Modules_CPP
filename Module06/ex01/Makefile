# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/30 15:47:09 by yasmine           #+#    #+#              #
#    Updated: 2026/07/04 21:11:19 by yasmine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serializer
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp serializer.cpp

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



NAME = ircserv

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -Iinc

SRC = src/Commands.cpp \
	src/Server.cpp \
	src/Channel.cpp \
	src/Client.cpp \
	src/main.cpp \

OBJ_DIR = obj
OBJ = $(SRC:src/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: src/%.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
//// 