/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:36:37 by rlins             #+#    #+#             */
/*   Updated: 2022/04/03 23:07:25 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int argument)
{
	int	length;

	length = ft_strlen(str);
	if (!ft_isascii(argument))
		return ((char *) &str[0]);
	while (length >= 0)
	{
		if (str[length] == argument)
			return ((char *) &str[length]);
		length--;
	}
	return ((void *) 0);
}
