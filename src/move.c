/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:07:31 by rlins             #+#    #+#             */
/*   Updated: 2022/08/21 10:50:49 by rlins            ###   ########.fr       */
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
	if (key == A_KEY_CONST || key == D_KEY_CONST)
	{
		// Destroing player img
		mlx_destroy_image(game->mlx, game->img_player);
		// Restoring player image
		if (key == D_KEY_CONST)
			game->img_player = mlx_xpm_file_to_image(game->mlx, P_XPM, &game->img_w, &game->img_h);
		else if (key == A_KEY_CONST)
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
	if (key == A_KEY_CONST)
		game->map[game->y_player][game->x_player + 1] = BACK_G_CONST;
	else
		game->map[game->y_player][game->x_player - 1] = BACK_G_CONST;
}

/**
 * @brief Reset the preveous space that the Person was there 
 * @param game 
 * @param key 
 */
static void	update_y_axio(t_game *game, char key)
{
	if (key == W_KEY_CONST)
		game->map[game->y_player + 1][game->x_player] = BACK_G_CONST;
	else if (key == S_KEY_CONST)
		game->map[game->y_player - 1][game->x_player] = BACK_G_CONST;
}

/**
 * @brief How the person will change, in this location
 * we must to 'reset' or 'put' the empty space back 
 * @param game Object game
 * @param key Key pressed
 */
static void	update_previous_char_to_empty(t_game *game, char key)
{
	if (key == W_KEY_CONST || key == S_KEY_CONST)
		update_y_axio(game, key);
	else if (key == A_KEY_CONST || key == D_KEY_CONST)
		update_x_axio(game, key);
}

void	press_key(t_game *game, char key)
{
	player_update_image(game, key);
	// if no More Collectons, and is exit
	if (game->map[game->y_player][game->x_player] == EXIT_CONST
			&& game->n_collectible == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		update_previous_char_to_empty(game, key);
		game->moves++;
		game->endgame = 1;
		map_draw_img(game);
	}
	// If you try hit a Wall or exit without collect all, it's not allow
	else if (game->map[game->y_player][game->x_player] == WALL_CONST
			|| game->map[game->y_player][game->x_player] == EXIT_CONST)
		person_rollback(game, key);
	else
	{
		// Clear (in blak) the given window
		mlx_clear_window(game->mlx, game->win);
		// Decrement collectable, if this is the type
		if (game->map[game->y_player][game->x_player] == COLLEC_CONST)
			game->n_collectible -= 1;
		game->map[game->y_player][game->x_player] = PLAYER_CONST;
		update_previous_char_to_empty(game, key);
		game->moves++;
		map_draw_img(game);
	}
}
