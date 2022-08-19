/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:31:20 by rlins             #+#    #+#             */
/*   Updated: 2022/08/18 22:34:42 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	start(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.map = load_map(argv[1]);
		if (valid_map(&game) && valid_extension(argv[1]))
		{
			load_game(&game);
			hooks_handler(&game);
			mlx_loop(game.mlx);
		}
		else
		{
			if (game.map)
				free_map(game.map);
			ft_printf("Error(1).\nInvalid Map. Verify specifications!!\n");
			exit(1);
		}
	} 
	else
	{
		ft_printf("Error(2).\nParam size wrong!!\n");
		// Stlib.h - Exit - close program
		exit(1);
	}
	return (0);
}
