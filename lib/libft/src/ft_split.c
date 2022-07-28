/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:01:18 by rlins             #+#    #+#             */
/*   Updated: 2022/04/12 15:22:08 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_str_count_word(const char *str, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] != c)
			word++;
		while (str[i] != c && str[i + 1])
			i++;
		i++;
	}
	return (word);
}

char	**ft_split(char const *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**result;

	i = 0;
	k = 0;
	result = (char **)malloc(sizeof(char *) * (ft_str_count_word(str, c) + 1));
	if (!str || !result)
		return (NULL);
	while (i < ft_str_count_word(str, c))
	{
		result[i] = (char *)malloc(sizeof(char) * (ft_strlen(&str[k]) + 1));
		if (!result[i])
			return (NULL);
		j = 0;
		while (str[k] == c)
			k++;
		while (str[k] != c && str[k])
			result[i][j++] = str[k++];
		result[i][j] = '\0';
		i++;
	}
	result[i] = '\0';
	return (result);
}
