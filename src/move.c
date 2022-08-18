/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:07:31 by rlins             #+#    #+#             */
/*   Updated: 2022/08/17 22:10:07 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	player_update_image(t_game *game, char key)
{
	mlx_destroy_image(game->mlx, game->img_player);
	if (key == 'w' || key == 'd' || key == 's')
		game->img_player = mlx_xpm_file_to_image(game->mlx, "img/p.xpm", &game->img_w, &game->img_h);
	else if (key == 'a')
		game->img_player = mlx_xpm_file_to_image(game->mlx, "img/pa.xpm", &game->img_w, &game->img_h);
}


static void	press_key(t_game *game, char key)
{
	player_update_image(game, key);

}

void	press_a(t_game *game)
{
	ft_printf("aaaaaaaaaaaaaaaa");
	press_key(game, 'a');
}

void	press_s(t_game *game)
{
	ft_printf("sssssssssssssssssssssssssss");
	press_key(game, 's');
}

void	press_d(t_game *game)
{
	ft_printf("dddddddddddddddddddd");
	press_key(game, 'd');
}

void	press_w(t_game *game)
{
	ft_printf("wwwwwwwwwwwwwwwwwwwwwww");
	press_key(game, 'w');
}