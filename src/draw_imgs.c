/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:20:42 by rlins             #+#    #+#             */
/*   Updated: 2022/08/14 22:41:43 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * IMG_PXL_SZ, y * IMG_PXL_SZ);
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
				put_img(game, game->img_player, x, y);
			else if (game->map[y][x] == 'C')
				put_img(game, game->img_collectible, x, y);
			else if (game->map[y][x] == 'E')
				put_img(game, game->img_exit, x, y);


			x++;
		}
		y++;
	}
}