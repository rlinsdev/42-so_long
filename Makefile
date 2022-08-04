# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlins <rlins@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 19:54:21 by rlins             #+#    #+#              #
#    Updated: 2022/08/04 16:49:55 by rlins            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH		=	./lib/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./lib/minilibx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

SOURCES_FILES	=	so_long.c \
					load_game.c \
					load_map.c
# SOURCES_FILES	=	so_long.c \
# 					draw.c \
# 					init.c \
# 					read_map.c \
# 					map_validate.c \
# 					player_update.c \
# 					gameplay.c \
# 					exit_game.c

#SOURCES_BONUS	=	so_long_bonus.c \
# SOURCES_BONUS	=	so_long_bonus.c \
# 					draw_bonus.c \
# 					init_bonus.c \
# 					read_map_bonus.c \
# 					map_validate_bonus.c \
# 					player_update_bonus.c \
# 					gameplay_bonus.c \
# 					exit_game_bonus.c \
# 					moves_bonus.c \
# 					animation_bonus.c

BINS_DIR 		= 	bin
OBJS_DIR 		= 	obj
SOURCES_DIR		=	src
SAFE_MKDIR = mkdir -p
#BONUS_DIR		=	sources_bonus

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck

HEADER			=	$(SOURCES_DIR)/so_long.h
#HEEADER_BONUS	=	$(BONUS_DIR)/so_long_bonus.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))
#BONUS_FILES		=	$(addprefix $(BONUS_DIR)/, $(SOURCES_BONUS))

OBJECTS			= 	$(SOURCES:.c=.o)
OBJS			=	$(SOURCES_FILES:%.c=$(OBJS_DIR)/%.o)
#OBJECTS_BONUS	= 	$(BONUS_FILES:.c=.o)

NAME			=	so_long
#NAME_BONUS		=	so_long_bonus

# Bash command
RM				=	rm -f

# Compilation
CC				=	clang
CFLAGS			=	-Wall -Wextra -Werror
MLXFLAGS		=	-L. -lXext -L. -lX11

$(OBJS_DIR)/%.o: ./$(SOURCES_DIR)/%.c 
	$(SAFE_MKDIR) $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# $(OBJS_DIR)/%.o: %.c $(OBJS_DIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

#.c.o:
#	${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}
#	$(SAFE_MKDIR) ./$(OBJS_DIR)
#	$(CC) $(CFLAGS) -c $< -o $@
#	$(CC) $(CFLAGS) -c $< -o ./$(OBJS_DIR)/$(NAME).o 
#	$(CC) $(CFLAGS) -c $(SOURCES) -o $(OBJS)

all:			$(NAME)

test:
	$(OBJECTS)

#bonus:			$(NAME_BONUS)

$(NAME):		$(LIBFT) $(MINILIBX) $(OBJECTS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o ./$(BINS_DIR)/$(NAME)

# $(NAME_BONUS):		$(LIBFT) $(MINILIBX) $(OBJECTS_BONUS) $(HEADER_BONUS)
# 					$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME_BONUS)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):
				$(MAKE) -C $(MINILIBX_PATH)

valgrind: $(NAME)
	$(VALGRIND)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(RM) $(OBJS) $(OBJECTS_BONUS)
				$(RM) ./$(BINS_DIR)/$(NAME)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME) $(NAME_BONUS)

norma: 
	norminette $(SOURCES)

re:				fclean all

.PHONY:			all clean fclean re libft minilibx bonus
