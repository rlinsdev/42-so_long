/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:40:33 by rlins             #+#    #+#             */
/*   Updated: 2022/04/06 21:45:18 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	lengh;
	char	*result;

	lengh = ft_strlen(src) + 1;
	result = (char *)malloc(lengh);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, src, lengh);
	return (result);
}
