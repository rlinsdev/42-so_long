/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:20:42 by rlins             #+#    #+#             */
/*   Updated: 2022/08/20 11:15:50 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/**
 * @brief Responsable to put a image in window. All the 
 * chars will use this call 
 * @param game 
 * @param img image setup previus
 * @param x coordinates define where the image should be placed in the window.
 * @param y coordinates define where the image should be placed in the window.
 */
static void	put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * IMG_PXL_SZ,
		y * IMG_PXL_SZ);
}

/**
 * @brief Set the up exit img object.
 * If This will be the last image (exit change) to show that player now must
 * exit the game 
 * @param game 
 * @param x coordinates define where the image should be placed in the window.
 * @param y coordinates define where the image should be placed in the window.
 */
static void	setup_exit_img(t_game *game, int x, int y)
{
	// If all collectible was done
	if (game->n_collectible == 0)
	{
		// Remove img actual
		mlx_destroy_image(game->mlx, game->img_exit);
		// Change img to new exit
		game->img_exit = mlx_xpm_file_to_image(
				game->mlx, EXIT_2_XPM, &game->img_w, &game->img_h);
	}
	put_img(game, game->img_exit, x, y);
}

/**
 * @brief Set the up player img object.
 * Update the user position (x_player and y_player)
 * @param game 
 * @param x coordinates define where the image should be placed in the window.
 * @param y coordinates define where the image should be placed in the window.
 */
static void	setup_player_img(t_game *game, int x, int y)
{
	game->x_player = x;
	game->y_player = y;
	put_img(game, game->img_player, x, y);
}

int	map_draw_img(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		// Loop between all the chars
		while (game->map[y][x])
		{
			if (game->map[y][x] == WALL_CONST)
				put_img(game, game->img_wall, x, y);
			else if (game->map[y][x] == BACK_G_CONST)
				put_img(game, game->img_empty, x, y);
			else if (game->map[y][x] == PLAYER_CONST)
				setup_player_img(game, x, y);
			else if (game->map[y][x] == COLLEC_CONST)
				put_img(game, game->img_collectible, x, y);
			else if (game->map[y][x] == EXIT_CONST)
				setup_exit_img(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
