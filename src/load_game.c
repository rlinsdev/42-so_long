/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:19:02 by rlins             #+#    #+#             */
/*   Updated: 2022/08/14 15:54:38 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	void window_size(t_game *game)
{
	int i;
	// Any line in map * 32 px
	game->map_w = ft_strlen(game->map[0]) * IMG_PXL;
	i = 0;
	while (game->map[i] != (void * )0)
		i++;
	game->map_h = i * IMG_PXL;
}

void	load_game(t_game *game)
{
	game->mlx = mlx_init();
	window_size(game);
	game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, "So_Long");
	ft_printf("\nAbrir janela\n");

	// Initialize variables
	game->moves = 0;
	//game->endgame = 0;

	

	//mlx_destroy_window(game->mlx, game->win);
	//free(game->mlx);
	
}