/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:56:49 by rlins             #+#    #+#             */
/*   Updated: 2022/04/12 20:08:48 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nblong;
	int		i;
	char	c[10];

	nblong = n;
	if (nblong == 0)
		ft_putchar_fd('0', fd);
	i = 0;
	if (nblong < 0)
	{
		ft_putchar_fd('-', fd);
		nblong = nblong * -1;
	}
	while (nblong > 0)
	{
		c[i] = nblong % 10 + 48;
		nblong = nblong / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar_fd(c[i], fd);
		i--;
	}
}
