/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:25:45 by rlins             #+#    #+#             */
/*   Updated: 2022/08/15 15:48:22 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**load_map(char *path)
{
	// TODO: Ponteiro de ponteiro. Pq?
	int		fd;
	char 	**map;
	char	*accumulator;
	char	*holder;
	char	*line;
	
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	accumulator = ft_strdup("");

	while(1)
	{
		line = get_next_line(fd);
		//ft_printf("Vlr Line: %s\n", line);
		if (!line)
			break;
		holder = accumulator;
		accumulator = ft_strjoin(holder, line);
		//ft_printf("Vlr do accumulator: %s\n", accumulator);
		free(line);
		free(holder);
	}
	map = ft_split(accumulator, '\n');
	free(accumulator);
	close(fd);
	return(map);
}