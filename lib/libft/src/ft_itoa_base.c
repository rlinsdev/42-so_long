/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 03:44:52 by rlins             #+#    #+#             */
/*   Updated: 2022/08/13 13:51:10 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

// unsigned long long: Pass test with LONG_MIN, INT_MIN
static	size_t	ft_inttobaselen(unsigned long long nbr, char* base)
{
	size_t				len;
	unsigned long long	baselen;

	len = 1;
	baselen = ft_strlen(base);
	// Calculate the size of cast to this base. Will be used in malloc
	while (nbr >= baselen)
	{
		nbr = nbr / baselen;
		len++;
	}
	return (len);
}

char* ft_itoa_base(unsigned long long nbr, char* base)
{
	char* result;
	int		i;
	int		sizeofbase;

	i = ft_inttobaselen(nbr, base);
	sizeofbase = ft_strlen(base);
	result = malloc((i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	// Last char (null char)
	result[i] = '\0';
	// Back to front
	while (i > 0)
	{
		i--;
		// Number mod base (16) = Char in base wanted
		// Mod result will be the value to add in result
		result[i] = base[nbr % sizeofbase];
		// decreese number to new calc 
		nbr = (nbr / sizeofbase);
	}
	return (result);
}