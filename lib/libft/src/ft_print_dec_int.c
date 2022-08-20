/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 04:03:10 by rlins             #+#    #+#             */
/*   Updated: 2022/08/20 17:10:10 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

int	ft_print_dec_int(long nbr)
{
	int			bytes;
	char		*result;
	int			neg;
	long long	aux;

	aux = nbr;
	neg = 0;
	if (aux < 0)
	{
		aux = aux * -1;
		neg = 1;
	}
	result = ft_itoa_base(aux, DEC_BASE);
	if (neg == 0)
		bytes = ft_print_string(result);
	else
	{
		bytes = ft_print_char('-');
		bytes += ft_print_string(result);
	}
	ft_free(result);
	return (bytes);
}
