/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:25:45 by rlins             #+#    #+#             */
/*   Updated: 2022/08/20 16:22:39 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**load_map(char *path)
{
	int		fd;
	char	**map;
	char	*accumulator;
	char	*holder;
	char	*line;
	
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	accumulator = ft_strdup(""); // TODO: Porque strdup?
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		holder = accumulator;
		accumulator = ft_strjoin(holder, line); // TODO: porque strjoin?
		free(line);
		free(holder);
	}
	map = ft_split(accumulator, '\n'); // Todo: porque dar split aqui?
	free(accumulator);
	close(fd);
	return (map);
}
