/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:44:14 by rlins             #+#    #+#             */
/*   Updated: 2022/04/06 21:43:43 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *des, const char *src, size_t len)
{	
	size_t			lensrc;
	unsigned int	i;

	i = 0;
	if (!des || !src)
		return (0);
	lensrc = ft_strlen(src);
	if (len <= 0)
		return (lensrc);
	while (src[i] != '\0' && (i < (len - 1)))
	{
		des[i] = src[i];
		i++;
	}
	des[i] = '\0';
	return (lensrc);
}
