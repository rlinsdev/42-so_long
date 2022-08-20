/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 03:59:54 by rlins             #+#    #+#             */
/*   Updated: 2022/08/20 17:05:49 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

int	ft_print_pointer(void *ptr)
{
	int				bytes;
	char			*str;
	unsigned long	address;

	if (!ptr)
	{
		bytes = ft_putstr(PTR_NULL);
		return (bytes);
	}
	address = (unsigned long)ptr;
	bytes = ft_putstr(INI_PTR);
	str = ft_itoa_base(address, HEX_BASE_LOWER);
	bytes += ft_putstr(str);
	ft_free(str);
	return (bytes);
}
