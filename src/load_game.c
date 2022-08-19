/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:19:02 by rlins             #+#    #+#             */
/*   Updated: 2022/08/19 08:16:45 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/**
 * @brief Responsable to get the size of window
 * @param game 
 */
static	void window_size(t_game *game)
{
	int i;
	// Any line in map * 32 px
	game->map_w = ft_strlen(game->map[0]) * IMG_PXL_SZ;
	i = 0;
	while (game->map[i] != (void *)0)
		i++;
	game->map_h = i * IMG_PXL_SZ;
}

/**
 * @brief Define the image for each object in game stucture.
 * All thte images will be draw by xpm file to image.
 * @param game
 */
static	void setup_imgs(t_game *game)
{
	// mlx_xpm_file_to_image Will read a image.
	game->img_empty = mlx_xpm_file_to_image(game->mlx, "img/0.xpm", &game->map_w, &game->map_h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "img/1.xpm", &game->map_w, &game->map_h);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, "img/c.xpm", &game->map_w, &game->map_h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "img/p.xpm", &game->map_w, &game->map_h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "img/e.xpm", &game->map_w, &game->map_h);
}

void	load_game(t_game *game)
{
	// Initialize MLX
	game->mlx = mlx_init();
	window_size(game);
	game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, "XX So_Long XX");
	// Initialize variables
	game->moves = 0;
	game->endgame = 0;
	setup_imgs(game);
	map_draw_img(game);
}