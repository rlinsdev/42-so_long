/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 08:01:21 by rlins             #+#    #+#             */
/*   Updated: 2022/08/13 09:26:28 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	exit_game(t_game *game)
{
	printf("\nChamou o exit game\n");
	// free_map(game->map);
	// mlx_destroy_image(game->mlx, game->img_backg);
	// mlx_destroy_image(game->mlx, game->img_wall);
	// mlx_destroy_image(game->mlx, game->img_player);
	// mlx_destroy_image(game->mlx, game->img_colect);
	// mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_window(game->mlx, game->win);
	// mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	// Must to be int to return in hooks
	return(0);
}
