/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:29:22 by rlins             #+#    #+#             */
/*   Updated: 2022/04/07 02:54:42 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_is_negative(long nb)
{
	if (nb >= 0)
		return (0);
	else
		return (1);
}

static long	ft_qtd_digits(long nb)
{
	long	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	char	*result;
	int		negative;
	int		digits;
	long	number;

	number = nb;
	negative = ft_is_negative(number);
	if (negative == 1)
		number = number * -1;
	digits = ft_qtd_digits(number);
	result = (char *) malloc(digits + negative + 1);
	if (result == NULL)
		return (NULL);
	if (negative == 1)
		result[0] = '-';
	result[digits + negative] = '\0';
	while (digits > 0)
	{
		result[(digits - 1) + negative] = (number % 10) + '0';
		number = number / 10;
		digits--;
	}
	return (result);
}
