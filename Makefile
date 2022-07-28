# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlins <rlins@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 19:15:33 by rlins             #+#    #+#              #
#    Updated: 2022/07/28 19:19:51 by rlins            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m


# PATH VARIABLES
HEADERS_PATH = ./include/
SRCS_PATH = ./src/
OBJS_PATH = ./obj/
LIBS_PATH = ./lib/
BINS_PATH = ./bin/

# COMPILATION
CC = gcc
FLAGS = -Wall -Wextra -Werror

# BASH COMMANDS
RM = rm -f
MKDIR = mkdir -p
MAKE_NOPRINT = $(MAKE) --no-print-directory

# FILES
LIBNAME = baseproject.a
SRC_FILES = float_vector.c \
			mytime.c
SOURCES = $(addprefix $(SRCS_PATH), $(SRC_FILES))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))
EXECUTABLE = ft_baseproject_test

# TARGETS
all: libft $(LIBNAME)

# -> compiles libft all over
libft:
	@echo "$(LIBNAME): $(BLUE)Generating... Just a minute$(RESET)"
	@cd $(LIBS_PATH)libft && $(MAKE_NOPRINT)
	@echo "$(LIBNAME): $(GREEN)Done!$(RESET)"

# -> creates static library libftprintf.a inside ./libs/
$(LIBNAME): $(OBJECTS)
	@cp $(LIBS_PATH)/libft.a $(LIBS_PATH)$(LIBNAME)
	@ar -rcs $(LIBS_PATH)$(LIBNAME) $(OBJECTS)

# -> creates object files for ft_printf (libftprintf)
$(OBJS_PATH)%.o : $(SRCS_PATH)%.c $(HEADERS_PATH)*.h
	@$(MKDIR) $(OBJS_PATH)
	@$(CC) $(FLAGS) -c $< -I $(HEADERS_PATH) -o $@

# -> mandatory flag for project submission
#bonus: all

# RUN
# -> creates the executable file $(EXECUTABLE) to test development
main:	./apps/app.c
	@$(MKDIR) $(BINS_PATH)
	@$(CC) $(CFLAGS) $< $(LIBS_PATH)$(LIBNAME) -I $(HEADERS_PATH) -o $(BINS_PATH)$(EXECUTABLE)

run: all main
	@$(BINS_PATH)$(EXECUTABLE)
	@$(MAKE_NOPRINT) fclean

# SANITIZE
# -> deletes all .o files; also runs libft's clean target
clean:
	@echo "$(LIBNAME): $(RED)object (*.o) files were deleted$(RESET)"
	@$(RM) $(OBJECTS)
	@cd $(LIBS_PATH)libft && $(MAKE_NOPRINT) $@

# -> deletes .o files + static library file + executable; also runs libft's fclean target
fclean: clean
	@echo "$(LIBNAME): $(RED)was deleted$(RESET)"
	@$(RM) $(BINS_PATH)$(EXECUTABLE)
	@$(RM) $(LIBS_PATH)$(LIBNAME)
	@cd $(LIBS_PATH)libft && $(MAKE_NOPRINT) $@

# -> 
re: fclean all

.PHONY: all run clean fclean re