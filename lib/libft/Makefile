# Collors
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

# Paths
HEADERS_PATH = ../../include/
SRCS_PATH = ./src/
OBJS_PATH = ./obj/
LIBS_PATH = ../

# Compilation
CC = gcc
FLAGS = -Wall -Wextra -Werror

# Bash commands
RM = rm -f
MKDIR = mkdir -p

# Files
LIBNAME = libft.a
SRC_FILES =	ft_free.c \
			ft_itoa_base.c \
			ft_print_char.c \
			ft_print_dec_int.c \
			ft_print_hexa.c \
			ft_print_pointer.c \
			ft_print_string.c \
			ft_printf.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_strlen.c \
			ft_get_next_line.c \
			ft_strchr.c \
			ft_isascii.c \
			ft_split.c \
			ft_substr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_memcmp.c

SOURCES = $(addprefix $(SRCS_PATH), $(SRC_FILES))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))

# Target
all: prep $(LIBNAME)

# Compiles
prep:
	@echo "$(LIBNAME): $(BLUE)Generating... Just a minute$(RESET)"
	@$(MKDIR) $(SRCS_PATH) $(OBJS_PATH)
	@echo "$(LIBNAME): $(GREEN)Done!$(RESET)"

$(LIBNAME): $(OBJECTS)
	@ar -rcs $(LIBS_PATH)$(LIBNAME) $(OBJECTS)

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c $(HEADERS_PATH)*.h
	@$(CC) $(FLAGS) -c -I $(HEADERS_PATH) $< -o $@

clean:
	@echo "$(GREEN)$(LIBNAME): $(RED)object (*.o) files were deleted$(RESET)"
	@$(RM) $(OBJECTS)

fclean:
	@echo "$(GREEN)$(LIBNAME): $(RED)was deleted$(RESET)"
	@$(RM) $(OBJECTS)
	@$(RM) $(LIBS_PATH)$(LIBNAME)

re: fclean all

.PHONY:	all clean fclean re