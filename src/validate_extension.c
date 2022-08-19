/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:05:26 by rlins             #+#    #+#             */
/*   Updated: 2022/08/19 19:10:30 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	valid_extension(char *path)
{
	int	len;

	// Must to exist the path of map
	if (!path)
		return (0);
	len = ft_strlen(path);
	// TODO: Se não houver leaks de memória, melhorar com substring isso aqui
	len -= 1;
	if (path[len] == 'r' && path[len - 1] == 'e' && path[len - 2] == 'b'
		&& path [len - 3] == '.')
		return (1);
	return (0);
}
