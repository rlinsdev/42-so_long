/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:30:04 by rlins             #+#    #+#             */
/*   Updated: 2022/04/06 15:55:40 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t len)
{
	void	*ptr;
	size_t	lentotal;

	if (nitems >= INT_MAX || len >= INT_MAX)
		return (NULL);
	lentotal = nitems * len;
	ptr = malloc(lentotal);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, lentotal);
	return (ptr);
}
