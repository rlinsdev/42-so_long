/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:31:20 by rlins             #+#    #+#             */
/*   Updated: 2022/08/04 16:02:53 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv) 
{
	t_game	game;

	if (argc == 2)
	{
		game.map = load_map(argv[1]);
		// game_init(&game);
		// mlx_loop(game.mlx);

	} 
	else
	{
		printf("Error. \n Param size wrong!!");
	}

	// if (argc == 2)
	// {
	// 	game.map = read_map(argv[1]);
	// 	if (map_checker(&game) && argv_checker(argv[1]))
	// 	{
	// 		game_init(&game);
	// 		gameplay(&game); 
	// 		mlx_loop(game.mlx);
	// }
	// 	else
	// 	{
	// 		if (game.map)
	// 			free_map(game.map);
	// 		printf("Error\nInvalid Map");
	// 		exit(1);
	// 	}
	// }
	// else
	// {
	// 	printf("Error\nInvalid Sytax");
	// 	exit(1);
	// }
	return (0);
}