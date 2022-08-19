/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:44:21 by rlins             #+#    #+#             */
/*   Updated: 2022/08/19 18:29:46 by rlins            ###   ########.fr       */
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
	char	**map; // Pointer to pointer. 2D character array.
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
 * @brief First method in game.
 * It'll be called by main / app.cs 
 * @param argc Arguments count
 * @param argv Arguments Vector
 * @return int 
 */
int	start(int argc, char **argv);

/**
 * @brief Will loop through all char in maps (.ber file)
 * and will put the correspondent img to each char 
 * @param game 
 * @return int 
 */
int	map_draw_img(t_game *game);

/**
 * @brief Will read the file map, line by line get all
 * the information, and return this like a 2D matrix 
 * @param path 
 * @return char** obj map
 */
char	**load_map(char *path);

/**
 * @brief Verify if the map is correct. Rectangular and with the 
 * specific tags 
 * @param game 
 * @return int (1 = valid) (0 = invalid)
 */
int		valid_map(t_game *game);

/**
 * @brief Capture the W press key 
 * @param game Object game
 */
void	press_w(t_game *game);

/**
 * @brief Capture the D press key 
 * @param game Object game
 */
void	press_d(t_game *game);

/**
 * @brief Capture the a press key 
 * @param game Object game
 */
void	press_a(t_game *game);

/**
 * @brief Capture the S press key 
 * @param game Object game
 */
void	press_s(t_game *game);

/**
 * @brief Will setup all the begin configuration of game.
 * Initializing all mlx configurations 
 * @param game Game object
 */
void	load_game(t_game *game);

/**
 * @brief Validate the extension of map
 * (.ber)
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
 * @brief Called by Hook key press.
 * Any key pressed in window, will call this function 
 * @param keycode 
 * @param game 
 * @return int. Important to MLX framework return a int
 */
int	key_press(int keycode, t_game *game);

/**
 * @brief Will clean all references about map
 * @param map 
 */
void	free_map(char **map);

#endif
