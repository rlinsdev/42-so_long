/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:31:20 by rlins             #+#    #+#             */
/*   Updated: 2022/08/14 10:13:56 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	start(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		//char *path;
		//path = argv[1];
		ft_printf("Mapa: %s\n", argv[1]);
		game.map = read_map(argv[1]);
		//ft_printf("Valor do path,%s", path);
		load_game(&game);
		hooks_handler(&game);
		mlx_loop(game.mlx);
	} 
	else
	{
		ft_printf("Error. \nParam size wrong!!\n");
		// Stlib.h - Exit - close program
		exit(1);
	}

	return (0);
}
