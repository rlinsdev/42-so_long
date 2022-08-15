/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 07:45:19 by rlins             #+#    #+#             */
/*   Updated: 2022/08/15 13:39:07 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	int valid_shape(char **map)
{
	int	i;
	
	i = 0;

	while (map[i] != (void *)0)
	{
		if(ft_strlen(map[0]) != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

static	int valid_char_pec(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	// Setup the number of Char
	game->n_collectible = 0;
	game->n_player = 0;
	game->n_exit = 0;

	while (game->map[i] != (void *)0)
	{
		j = 0;
		while (game->map[i][j] != (void *)0)
		{
			if(game->map[i][j] == 'P')
				game->n_player++;
			if(game->map[i][j] == 'C')
				game->n_collectible++;
			if(game->map[i][j] == 'E')
				game->n_exit++;
			j++;
		}
		i++;
	}
	ft_printf("AAAA");
	// Verify number of occurrence
	if (game->n_player != 1 || game->n_exit == 0 || game->n_collectible == 0)
		return (0);
	return(1);
}

// TODO: Porque um char de ponteiro pra ponteiro?
static	int valid_all_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i][j] != (void *)0) // TODO: Não poderia ser void null ou só ! ???
	{
		j = 0;
		
		while (map[i][j] != '\0')
		{
			if(map[i][j] != 'P' &&
				map[i][j] != 'E' &&
				map[i][j] != 'C' &&
				map[i][j] != '0' &&
				map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_map(t_game *game)
{
	if (valid_shape(game->map) && valid_char_pec(game) && valid_all_char(game->map))
		return (1);
	else
		return (0);
}