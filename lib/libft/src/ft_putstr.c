/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 03:51:08 by rlins             #+#    #+#             */
/*   Updated: 2022/08/13 13:50:46 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

int	ft_putstr(char* str)
{
	int	i;

	i = 0;
	if (str == NULL)
		str = STR_NULL;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
