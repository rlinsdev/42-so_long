/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:25:45 by rlins             #+#    #+#             */
/*   Updated: 2022/08/21 10:06:47 by rlins            ###   ########.fr       */
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
	accumulator = ft_strdup(""); // Return a pointer to a string empty
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		holder = accumulator;
		accumulator = ft_strjoin(holder, line); // Join all file, line by line
		free(line);
		free(holder);
	}
	map = ft_split(accumulator, '\n'); // Map will received ** from split (2D Char)
	free(accumulator);
	close(fd);
	return (map);
}
