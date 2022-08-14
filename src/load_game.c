/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:19:02 by rlins             #+#    #+#             */
/*   Updated: 2022/08/14 16:57:19 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	void window_size(t_game *game)
{
	int i;
	// Any line in map * 32 px
	game->map_w = ft_strlen(game->map[0]) * IMG_PXL_SZ;
	i = 0;
	while (game->map[i] != (void * )0)
		i++;
	game->map_h = i * IMG_PXL_SZ;
}

static	void setup_imgs(t_game *game)
{
	game->img_backgroud = mlx_xpm_file_to_image(
		game->mlx, "img/1.xpm", &game->map_w, &game->map_h);
}

void	load_game(t_game *game)
{
	game->mlx = mlx_init();
	window_size(game);
	game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, "So_Long");
	//ft_printf("\nAbrir janela\n");

	// Initialize variables
	game->moves = 0;
	//game->endgame = 0;
	setup_imgs(game);
	ft_printf("entrou????");
	map_draw_img(game);

	

	//mlx_destroy_window(game->mlx, game->win);
	//free(game->mlx);
	
}