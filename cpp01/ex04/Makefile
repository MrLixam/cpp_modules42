# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 14:40:18 by lvincent          #+#    #+#              #
#    Updated: 2023/12/12 04:40:07 by lvincent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m

RED = \033[0;31m

RED_B = \033[1;31m

YELLOW = \033[1;33m

BLUE = \033[0;34m

RESET = \033[0m

NAME = Sed

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

all : $(NAME)

bonus : $(BONUS)

.cpp.o :
	@echo "$(GREEN)Compiling $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME) : $(OBJ)
	@echo "$(BLUE)Compiled object files for $(NAME)$(RESET)"
	@$(CXX) $(OBJ) $(LIBFT) $(CXXFLAGS) -o $(NAME)
	@echo "$(YELLOW)Compiled $(NAME)$(RESET)"

clean :
	@rm -f $(OBJ)
	@echo "$(RED)Removed object files from project and dependencies$(RESET)"

fclean :
	@rm -f $(OBJ)
	@echo "$(RED)Removed object files from project and dependencies$(RESET)"
	@rm -f $(NAME)
	@echo "$(RED_B)Removed $(NAME)$(RESET)"

re : fclean all

.PHONY : all clean fclean re