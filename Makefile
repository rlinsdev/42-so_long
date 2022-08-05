# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlins <rlins@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 19:15:33 by rlins             #+#    #+#              #
#    Updated: 2022/08/05 08:04:47 by rlins            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

# Minilibx
MINILIBX_PATH	=	./lib/minilibx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

# Compilation
CC = gcc
FLAGS = -Wall -Wextra -Werror
#MLXFLAGS =	-L. -lXext -L. -lX11
#MLXFLAGS =	-lmlx -Imlx -lXext -lX11
MLXFLAGS =  -ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11

# Bash commands
RM = rm -f # -f Force
MKDIR = mkdir -p
MAKE_NOPRINT = $(MAKE) --no-print-directory

# Files
LIBNAME = solong.a
SRC_FILES = so_long.c load_game.c load_map.c

SOURCES = $(addprefix $(SRCS_PATH), $(SRC_FILES))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))
EXECUTABLE = so_long

# TARGETS
all: libft $(LIBNAME)

# Compiles libft all over
libft:
	@echo "$(LIBNAME): $(BLUE)Generating... Just a minute$(RESET)"
	@cd $(LIBS_PATH)libft && $(MAKE_NOPRINT)
	@echo "$(LIBNAME): $(GREEN)Done!$(RESET)"

# Creates static library libft.a inside ./libs/ folder
$(LIBNAME): $(OBJECTS) $(MINILIBX)
	cp $(LIBS_PATH)/libft.a $(LIBS_PATH)$(LIBNAME)
	ar -rcs $(LIBS_PATH)$(LIBNAME) $(OBJECTS)

# Creates object files for ft_solong
$(OBJS_PATH)%.o : $(SRCS_PATH)%.c $(HEADERS_PATH)*.h
	$(MKDIR) $(OBJS_PATH)
	$(CC) $(FLAGS) $(MLXFLAGS) -c $< -I $(HEADERS_PATH) -o $@
	$(MAKE) -C $(MINILIBX_PATH)

#
# RUN
#
# Creates the executable file $(EXECUTABLE) to test development
main:	./apps/app.c
	@$(MKDIR) $(BINS_PATH)
	$(CC) $(CFLAGS) $(MINILIBX) $(MLXFLAGS) $< $(LIBS_PATH)$(LIBNAME) -I $(HEADERS_PATH) -o $(BINS_PATH)$(EXECUTABLE)

# Compile program and execute main file
run: all main
	@$(BINS_PATH)$(EXECUTABLE) 'PATH_DO_MAPA_AQUI!'

#
# SANITIZE
#
clean:
	@echo "$(GREEN)$(LIBNAME): $(RED)object (*.o) files were deleted$(RESET)"
	@$(RM) $(OBJECTS)
	@echo "$(GREEN)Minilibx: $(RED)Clean in progres...$(RESET)"
	$(MAKE) -C $(MINILIBX_PATH) clean
	@cd $(LIBS_PATH)libft && $(MAKE_NOPRINT) $@

# Removing .o files, .a files
fclean: clean
	@echo "$(GREEN)$(LIBNAME): $(RED)was deleted$(RESET)"
	@$(RM) $(BINS_PATH)$(EXECUTABLE)
	@$(RM) $(LIBS_PATH)$(LIBNAME)
	@cd $(LIBS_PATH)libft && $(MAKE_NOPRINT) $@

norma: 
	norminette $(SRCS_PATH)$(SRC_FILES)

# Removing and running
re: fclean all

.PHONY: all run clean fclean re