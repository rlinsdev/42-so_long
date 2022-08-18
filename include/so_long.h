/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:44:21 by rlins             #+#    #+#             */
/*   Updated: 2022/08/17 21:47:40 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/minilibx-linux/mlx.h"
# include "./libft.h"
// # include <stdio.h>
# include <fcntl.h> // To Open a file
#include <X11/keysym.h> // TODO: Ver se isso é proibido
#include <X11/X.h> // TODO: Ver se isso é proibido

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map; // TODO: Porque ponteiro de ponteiro?
	void	*img_empty;
	void	*img_wall;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	int		n_collectible;
	int		n_player;
	int		n_exit;
 	int		x_player;
 	int		y_player;
 	int		moves;
 	int		endgame;
}	t_game;

# define IMG_PXL_SZ 32
// # define KEY_ESC 65307
// # define KEY_Q 113

// # define KEY_W 119
// # define KEY_A 97
// # define KEY_S 115
// # define KEY_D 100

// # define KEY_UP 65362
// # define KEY_LEFT 65361
// # define KEY_DOWN 65364
// # define KEY_RIGHT 65363

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	start(int argc, char **argv);
// void	img_draw(t_game *game, void *image, int x, int y);
// int		map_draw(t_game *game);
void	map_draw_img(t_game *game);
// void	game_init(t_game *game);
// char	**read_map(char *path);
char	**load_map(char *path);

/**
 * @brief Verify if the map is correct. Rectangular and with the 
 * specific tags 
 * @param game 
 * @return int (1 = valid) (0 = invalid)
 */
int		valid_map(t_game *game);
// void	player_w(t_game *game);
// void	player_d(t_game *game);
// void	player_s(t_game *game);
// void	player_a(t_game *game);
void	press_w(t_game *game);
void	press_d(t_game *game);
void	press_a(t_game *game);
void	press_s(t_game *game);

/**
 * @brief 
 * 
 * @param game 
 */
void	load_game(t_game *game);

/**
 * @brief
 * 
 * @param path 
 * @return int 
 */
int	valid_extension(char *path);

/**
 * @brief Will handler the hooks - Mlx with windows actions
 * @param game obj game by ref
 */
void	hooks_handler(t_game *game);

/**
 * @brief Responsable to exit the game. Will close the window and destroy
 * the objects 
 * @param game 
 * @return int - Any thing. Must to be int return in hooks 
 */
int	exit_game(t_game *game);

/**
 * @brief All the business about key press will be here. 
 * @param keycode Code of key pressed
 * @param game obj game by ref
 * @return int - Key Code pressed
 */
int	key_press(int keycode, t_game *game);

/**
 * @brief Will clean all references about map
 * @param map 
 */
void	free_map(char **map);

#endif
