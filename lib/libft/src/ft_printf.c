/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 03:52:45 by rlins             #+#    #+#             */
/*   Updated: 2022/08/20 17:08:55 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

static int	ft_manage_specifier(va_list arg, char specifier)
{
	int	bytes;

	bytes = 0;
	if (specifier == '%')
		bytes += ft_print_char('%');
	else if (specifier == 'c')
		bytes += ft_print_char(va_arg(arg, int));
	else if (specifier == 's')
		bytes += ft_print_string(va_arg(arg, char *));
	else if (specifier == 'i' || specifier == 'd')
		bytes += ft_print_dec_int(va_arg(arg, int));
	else if (specifier == 'p')
		bytes += ft_print_pointer(va_arg(arg, void *));
	else if (specifier == 'u')
		bytes += ft_print_dec_int(va_arg(arg, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		bytes += ft_print_hexa(va_arg(arg, unsigned int), specifier);
	return (bytes);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		bytes;
	int		i;
	char	specifier;

	i = 0;
	bytes = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			specifier = str[i + 1];
			bytes += ft_manage_specifier(args, specifier);
			i++;
		}
		else
			bytes += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (bytes);
}
