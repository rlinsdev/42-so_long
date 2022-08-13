/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:42:50 by rlins             #+#    #+#             */
/*   Updated: 2022/08/13 14:45:59 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*mark;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	mark = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (mark);
	// char	*result;
	// int		size;

	// size = ft_strlen(s1) + ft_strlen(s2) + 1;
	// result = malloc(size * sizeof(char));
	// if (result == NULL)
	// 	return (NULL);
	// ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	// ft_strlcat(result, s2, size);
	// return (result);
}