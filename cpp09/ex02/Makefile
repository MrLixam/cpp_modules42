# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 05:51:01 by lvincent          #+#    #+#              #
#    Updated: 2024/03/23 15:14:52 by lvincent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[1;32m

RED = \033[1;31m

RESET = \033[0m

CC 		=	c++ 

FLAGS 	=	-Werror -Wall -Wextra -std=c++98
NAME 	=	Bureaucrats

SRC_DIR = src

OBJ_DIR = obj

SRC 	=	src/main.cpp src/Bureaucrat.cpp src/AForm.cpp src/ShrubberyCreationForm.cpp src/RobotomyRequestForm.cpp src/PresidentialPardonForm.cpp src/Intern.cpp

OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@printf "$(GREEN)$(NAME) [Compiling ...]$(RESET) $<\n"
	@$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@printf "$(GREEN)$(NAME) [Executable created]\n"

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(RED)$(NAME) [Removed sources]$(RESET)\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "$(RED)$(NAME) [Executable deleted]$(RESET)\n"

re: fclean all

debug: FLAGS += -g
debug: $(NAME)

.PHONY: all clean fclean re debug