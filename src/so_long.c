/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:31:20 by rlins             #+#    #+#             */
/*   Updated: 2022/08/13 10:16:09 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	start(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		char *path;
		path = argv[1];
		printf("Valor do path,%s", path);
		load_game(&game);
		hooks_handler(&game);
		mlx_loop(game.mlx);
	} 
	else
	{
		printf("Error. \nParam size wrong!!\n");
		printf("Error. \nParam size wrong!!\n");
		printf("Error. \nParam size wrong!!\n");
		printf("Error. \nParam size wrong!!\n");
	}

	return (game.moves );
}
