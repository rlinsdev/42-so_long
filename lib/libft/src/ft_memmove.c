/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:55:49 by rlins             #+#    #+#             */
/*   Updated: 2022/04/12 19:12:34 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *des, void *src, size_t len)
{
	unsigned int	i;

	if (des == NULL || src == NULL)
		return (NULL);
	if (des < src)
	{
		i = 0;
		while (i < len)
		{
			((char *) des)[i] = ((char *) src)[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			((char *) des)[i - 1] = ((char *) src)[i - 1];
			i--;
		}
	}
	return (des);
}
