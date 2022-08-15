/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 07:45:19 by rlins             #+#    #+#             */
/*   Updated: 2022/08/15 08:05:43 by rlins            ###   ########.fr       */
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

int	valid_map(t_game *game)
{
	if (valid_shape(game->map))
		return (1);
	else
		return (0);
}