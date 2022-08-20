/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:44:21 by rlins             #+#    #+#             */
/*   Updated: 2022/08/20 17:17:05 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/minilibx-linux/mlx.h"
# include "./libft.h"
# include <fcntl.h> // To Open a file
#include <X11/keysym.h> // Type key code pressed
#include <X11/X.h> // Type event em mask that hooks call

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

# define A_KEY_CONST	'a'
# define S_KEY_CONST	's'
# define D_KEY_CONST	'd'
# define W_KEY_CONST	'w'

# define WALL_CONST		'1'
# define BACK_G_CONST 	'0'
# define COLLEC_CONST  	'C'
# define PLAYER_CONST	'P'
# define EXIT_CONST		'E'

# define EMPTY_XPM 		"img/0.xpm"
# define WALL_XPM 		"img/1.xpm"
# define COLLE_XPM 		"img/c.xpm"
# define EXIT_XPM 		"img/e.xpm"
# define EXIT_2_XPM 	"img/e-2.xpm"
# define P_A_XPM 		"img/pa.xpm"
# define P_XPM 			"img/p.xpm"

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
 * @brief Hooks looks like a trigger.
 * This method will handler the hooks in project.
 * @param game 
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

/**
 * @brief Responsable to update all the variables to make the 
 * feeling of movement of the char. Will update and change the images
 * calling the correct methods 
 * @param game 
 * @param key 
 */
void	press_key(t_game *game, char key);

/**
 * @brief Will Rollback the position player.
 * How he is hit a invalid char (wall or exit) not allow, 
 * comming back to original state 
 * @param game Game object
 * @param key Key pressed
 */
void person_rollback(t_game *game, char key);

#endif
