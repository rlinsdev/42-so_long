# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlins <rlins@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 19:15:33 by rlins             #+#    #+#              #
#    Updated: 2022/08/20 16:11:19 by rlins            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Collors
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

# Paths
HEADERS_PATH = ./include/
SRCS_PATH = ./src/
OBJS_PATH = ./obj/
LIBS_PATH = ./lib/
BINS_PATH = ./bin/

# maps
#MAP = maps/map_15x34.ber
#MAP = maps/map_3x13.ber
#MAP = maps/map_5x13.ber
MAP = maps/map_6x34.ber

# Minilibx
MINILIBX_PATH	=	./lib/minilibx-linux
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

# Compilation
CC = gcc
FLAGS = -Wall -Wextra -Werror

#Chedk Leak memory
LEAK = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s

MLXFLAGS = -lmlx -lXext -lX11

# Bash commands
RM = rm -f # -f Force
MKDIR = mkdir -p
MAKE_NOPRINT = $(MAKE) --no-print-directory

# Files
SRC_FILES = so_long.c \
			load_game.c \
			load_map.c \
			exit_game.c \
			hooks.c \
			key_events.c \
			draw_imgs.c \
			validate.c \
			move.c \
			validate_extension.c \
			key_press_move.c

SOURCES = $(addprefix $(SRCS_PATH), $(SRC_FILES))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))
EXECUTABLE = so_long

# test:
# 	@echo $(BINS_PATH)$(EXECUTABLE) $(MAP)

# Targets
all: libft $(NAME)

# Compiles libft all over
libft:
	@echo "$(NAME): $(BLUE)Generating... Just a minute$(RESET)"
	@cd $(LIBS_PATH)libft && $(MAKE_NOPRINT)
	@echo "$(NAME): $(GREEN)Done!$(RESET)"

# Creates static library libft.a inside ./libs/ folder
$(NAME): $(OBJECTS) $(MINILIBX)
	cp $(LIBS_PATH)/libft.a $(LIBS_PATH)$(NAME)
	ar -rcs $(LIBS_PATH)$(NAME) $(OBJECTS)

# Creates object files for ft_solong
$(OBJS_PATH)%.o : $(SRCS_PATH)%.c $(HEADERS_PATH)*.h
	$(MKDIR) $(OBJS_PATH)
	$(CC) $(FLAGS) $(MLXFLAGS) -c $< -I $(HEADERS_PATH) -o $@
	$(MAKE) -C $(MINILIBX_PATH)

# Creates the executable file $(EXECUTABLE) to test development
main:	./apps/app.c
	@$(MKDIR) $(BINS_PATH)
	$(CC) $(FLAGS) $(OBJECTS) $(MINILIBX) $(MLXFLAGS) $< $(LIBS_PATH)$(NAME) -I $(HEADERS_PATH) -o $(BINS_PATH)$(EXECUTABLE)

# Compile program and execute main file
run: all main
	@$(BINS_PATH)$(EXECUTABLE) $(MAP)

# Sanitize
clean:
	@echo "$(GREEN)$(NAME): $(RED)object (*.o) files were deleted$(RESET)"
	@$(RM) $(OBJECTS)
	@echo "$(GREEN)Minilibx: $(RED)Clean in progres...$(RESET)"
	$(MAKE) -C $(MINILIBX_PATH) clean
	@cd $(LIBS_PATH)libft && $(MAKE_NOPRINT) $@

# Removing .o files, .a files
fclean: clean
	@echo "$(GREEN)$(NAME): $(RED)was deleted$(RESET)"
	@$(RM) $(BINS_PATH)$(EXECUTABLE)
	@$(RM) $(LIBS_PATH)$(NAME)
	@cd $(LIBS_PATH)libft && $(MAKE_NOPRINT) $@

norma: 
	norminette $(SOURCES)

valgrind:
	$(LEAK) $(BINS_PATH)$(EXECUTABLE) $(MAP)

# Removing and running
re: fclean all

# All the variables that is not a file in source folder.
.PHONY: all run clean fclean re