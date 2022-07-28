# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlins <rlins@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 16:09:27 by rlins             #+#    #+#              #
#    Updated: 2022/07/28 18:39:05 by rlins            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

CC = gcc -c 

FLAGS = -Wall -Wextra -Werror

AR = ar -rcs

SRCS = *.c
OBJ = *.o

all: $(NAME) 

$(NAME):
	@echo "$(BLUE)(just) a minute ⌛...$(RESET)"
	$(CC) $(FLAGS) $(SRCS)
	$(AR) $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "\n$(NAME): $(GREEN)$(NAME) was created ✓$(RESET)"
	@echo
	

clean:
	@echo "\n$(NAME): $(RED)object (*.o) files were deleted ✗$(RESET)"
	/bin/rm -f $(OBJ)
	@echo

fclean: clean
	@echo "$(NAME): $(RED)$(NAME) was deleted ✗$(RESET)"
	/bin/rm -rf $(NAME)
	@echo

re: fclean all

.PHONY: all clean fclean re
