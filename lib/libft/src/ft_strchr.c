/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:52:16 by rlins             #+#    #+#             */
/*   Updated: 2022/04/08 01:28:46 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int argument)
{
	int	i;

	i = 0;
	if (!ft_isascii(argument))
		return ((char *) &str[i]);
	while (str[i])
	{
		if (str[i] == argument)
			return ((char *) &str[i]);
		i++;
	}
	if (argument == '\0')
		return ((char *) &str[i]);
	return (NULL);
}
