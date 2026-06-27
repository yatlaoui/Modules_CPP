# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/17 16:11:07 by yasmine           #+#    #+#              #
#    Updated: 2026/06/27 12:45:41 by yasmine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = intern
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp Bureaucrat.cpp AForm.cpp \
	PresidentialPardonForm.cpp \
	RobotomyRequestForm.cpp \
	ShrubberyCreationForm.cpp \
	Intern.cpp \

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
