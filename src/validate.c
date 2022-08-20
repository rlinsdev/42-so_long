/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 07:45:19 by rlins             #+#    #+#             */
/*   Updated: 2022/08/20 16:06:28 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/**
 * @brief Check if the map is retangular
 * @param map 
 * @return int 
 */
static int	valid_shape(char **map)
{
	int	i;

	i = 0;
	while (map[i] != (void *)0)
	{
		// Check if the first line in map is the same size compare with others.
		if (ft_strlen(map[0]) != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Count and validate all chars P C E
 * @param game 
 * @return int 
 */
static int	valid_char_pec(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	// Startup the number of Char
	game->n_collectible = 0;
	game->n_player = 0;
	game->n_exit = 0;
	// loop between all itens in map
	while (game->map[i] != (void *)0) // comparison between pointer and zero
	{
		j = 0;
		while (game->map[i][j] != '\0') // comparison between pointer and integer
		{
			if(game->map[i][j] == PLAYER_CONST)
				game->n_player++; // Number of players in game
			if(game->map[i][j] == COLLEC_CONST)
				game->n_collectible++; // Number of Collectibles in game
			if(game->map[i][j] == EXIT_CONST)
				game->n_exit++; // Number of exits in game
			j++;
		}
		i++;
	}
	// Verify number of occurrence
	if (game->n_player != 1 || game->n_exit == 0 || game->n_collectible == 0)
		return (0);
	return (1);
}

/**
 * @brief Responsable to validate all the char in map
 * @param map. Pointer to pointer. 2D Char array
 * @return int 
 */
static int	valid_all_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != (void *)0) // comparison between pointer and zero
	{
		j = 0;
		while (map[i][j] != '\0') // comparison between pointer and integer
		{
			// The chars must be between this 5 types
			if (map[i][j] != PLAYER_CONST &&
				map[i][j] != EXIT_CONST &&
				map[i][j] != COLLEC_CONST &&
				map[i][j] != BACK_G_CONST &&
				map[i][j] != WALL_CONST)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * @brief Verify if all the boards are number 1 (Wall). 
 * 
 * @param map 
 * @return int 
 */
static	int valid_wall(char **map)
{
	int	i;
	int	j;
	int	colum_size;

	i = 0;
	j = 0;
	// Count all the line
	while (map[i] != (void *)0)
		i++;
	// Will validate the first and the last line
	while (map[0][j] != '\0' && map[i - 1][j] != '\0')
	{
		if (map[0][j] != WALL_CONST || // First line in array
			map[i - 1][j] != WALL_CONST) // Last line in array
			return (0);
		j++;
	}
	// Will validate the firs and the last colum
	i = 1;
	colum_size = ft_strlen(map[i]);
	while (map[i] != (void *)0)
	{
		if (map[i][0] != WALL_CONST || // First register
			map[i][(colum_size-1)] != WALL_CONST) // Last register
			return (0);
		i++;
	}
	return (1);
}

int	valid_map(t_game *game)
{
	if (valid_shape(game->map) && valid_char_pec(game)
		&& valid_all_char(game->map) && valid_wall(game->map))
		return (1);
	else
		return (0);
}
