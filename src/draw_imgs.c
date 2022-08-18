/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:20:42 by rlins             #+#    #+#             */
/*   Updated: 2022/08/18 08:00:24 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_img(t_game *game, void *img, int x, int y) // TODO: Teria q ser estático?
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * IMG_PXL_SZ, y * IMG_PXL_SZ);
}


static	void setup_exit_img(t_game *game, void *img, int x, int y)
{
	// Just finish if all collectibles was collected
	if (game->n_collectible == 0)
	{
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image(
			game->mlx, "img/e-2.xpm", &game->img_w, &game->img_h);

	}
	put_img(game, game->img_exit, x, y);
}


static	void setup_player_img(t_game *game, void *img, int x, int y)
{
	game->x_player = x;
	game->y_player = y;
	put_img(game, game->img_player, x, y);
}

void	map_draw_img(t_game *game)
{
	int	x;
	int y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				put_img(game, game->img_wall, x, y);
			else if (game->map[y][x] == '0')
				put_img(game, game->img_empty, x, y);
			else if (game->map[y][x] == 'P')
				setup_player_img(game, game->img_player, x, y);
			else if (game->map[y][x] == 'C')
				put_img(game, game->img_collectible, x, y);
			else if (game->map[y][x] == 'E')
				setup_exit_img(game, game->img_exit, x, y);
			x++;
		}
		y++;
	}
}
