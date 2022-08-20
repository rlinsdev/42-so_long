/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:05:26 by rlins             #+#    #+#             */
/*   Updated: 2022/08/20 16:07:39 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	valid_extension(char *path)
{
	int		i;
	int		len;
	char	*extension;

	len = ft_strlen(path);
	extension = "reb.";
	i = 4;
	while (i > 0)
	{
		if (path[len - i] != extension[i - 1])
			return (0);
		i--;
	}
	return (1);
}
