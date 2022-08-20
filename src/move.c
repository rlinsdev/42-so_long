/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:07:31 by rlins             #+#    #+#             */
/*   Updated: 2022/08/20 11:06:34 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/**
 * @brief Responsable to let the player img to right or left.
 * Will change just when press 'a' or 'd'
 * @param game obj key
 * @param key key pressed
 */
static void	player_update_image(t_game *game, char key)
{
	if(key == 'a' || key == 'd')
	{
		// Destroing player img
		mlx_destroy_image(game->mlx, game->img_player);
		// Restoring player image
		if (key == 'd')
			game->img_player = mlx_xpm_file_to_image(game->mlx, P_XPM, &game->img_w, &game->img_h);
		else if (key == 'a')
			game->img_player = mlx_xpm_file_to_image(game->mlx, P_A_XPM, &game->img_w, &game->img_h);
	}
}

/**
 * @brief Reset the preveous space that the Person was there 
 * @param game 
 * @param key 
 */
static void	update_x_axio(t_game *game, char key)
{
	if (key == 'a')
		game->map[game->y_player][game->x_player + 1] = '0';
	else
		game->map[game->y_player][game->x_player - 1] = '0';
}

/**
 * @brief Reset the preveous space that the Person was there 
 * @param game 
 * @param key 
 */
static	void update_y_axio(t_game *game, char key)
{
	if (key == 'w')
		game->map[game->y_player + 1][game->x_player] = '0';
	else if (key == 's')
		game->map[game->y_player - 1][game->x_player] = '0';
}

/**
 * @brief Will Rollback the position player.
 * How he is hit a invalid char (wall or exit) not allow, 
 * comming back to original state 
 * @param game Game object
 * @param key Key pressed
 */
static void person_rollback(t_game *game, char key)
{
	if (key == 'w')
		game->y_player += 1;
	else if (key == 'a')
		game->x_player += 1;
	else if (key == 'd')
		game->x_player -= 1;
	else if (key == 's')
		game->y_player -= 1;
}

/**
 * @brief How the person will change, in this location
 * we must to 'reset' or 'put' the empty space back 
 * @param game Object game
 * @param key Key pressed
 */
static void update_previous_char_to_empty(t_game *game, char key)
{
	if(key == 'w' || key == 's')
		update_y_axio(game, key);
	else if (key == 'a' || key == 'd')
		update_x_axio(game, key);
}

/**
 * @brief Responsable to update all the variables to make the 
 * feeling of movement of the char. Will update and change the images
 * calling the correct methods 
 * @param game 
 * @param key 
 */
static void	press_key(t_game *game, char key)
{
	player_update_image(game, key);

	// if no More Collectons, and is exit
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->n_collectible == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		update_previous_char_to_empty(game, key);
		game->moves++;
		game->endgame = 1;
		map_draw_img(game);
	}
	// If you try hit a Wall or exit without collect all, it's not allow
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		person_rollback(game, key);
	else
	{
		mlx_clear_window(game->mlx, game->win);
		// Decrement collectable, if this is the type
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_collectible -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		update_previous_char_to_empty(game, key);
		game->moves++;
		map_draw_img(game);
	}
}

void	press_a(t_game *game)
{
	// Update Person position
	game->x_player -= 1;
	press_key(game, 'a');
}

void	press_s(t_game *game)
{
	// Update Person position
	game->y_player += 1;
	press_key(game, 's');
}

void	press_d(t_game *game)
{
	// Update Person position
	game->x_player += 1;
	press_key(game, 'd');
}

void	press_w(t_game *game)
{
	// Update Person position
	game->y_player -= 1;
	press_key(game, 'w');
}