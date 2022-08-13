/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:44:21 by rlins             #+#    #+#             */
/*   Updated: 2022/08/13 09:01:10 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/minilibx-linux/mlx.h"
# include "./libft.h"
# include <stdio.h>
# include <fcntl.h>
#include <X11/keysym.h> // TODO: Ver se isso é proibido

typedef struct s_game
{
 	void	*mlx;
 	void	*win;
 	char	**map;
// 	void	*img_backg;
// 	void	*img_wall;
// 	void	*img_player;
// 	void	*img_colect;
// 	void	*img_exit;
// 	int		map_w;
// 	int		map_h;
// 	int		img_w;
// 	int		img_h;
// 	int		n_colect;
// 	int		n_player;
// 	int		n_exit;
// 	int		x_player;
// 	int		y_player;
 	int		moves;
// 	int		endgame;
}	t_game;

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
// void	game_init(t_game *game);
//char	**read_map(char *path);
void	read_map();
char	**load_map(char *path);
// int		map_checker(t_game *game);
// void	player_w(t_game *game);
// void	player_d(t_game *game);
// void	player_s(t_game *game);
// void	player_a(t_game *game);

/**
 * @brief 
 * 
 * @param game 
 */
void	load_game(t_game *game);

/**
 * @brief Will handler the hooks - Mlx with windows actions
 * 
 * @param game obj game by ref
 */
void	hooks_handler(t_game *game);

/**
 * @brief Responsable to exit the game. Will close the window and destroy
 * the objects 
 * @param game 
 * @return void 
 */
void	exit_game(t_game *game);

/**
 * @brief All the business about key press will be here. 
 * @param keycode Code of key pressed
 * @param game obj game by ref
 * @return int - Key Code pressed
 */
int	key_press(int keycode, t_game *game);


// void	free_map(char **map);

#endif
