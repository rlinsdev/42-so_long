/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:28:13 by rlins             #+#    #+#             */
/*   Updated: 2022/07/26 19:34:34 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: Remove Apps Folder finalize project
#include "../include/float_vector.h"
#include <stdio.h>

int	main() 
{
	FloatVector *vec = FloatVector_create(2);
	FloatVector_print(vec);

	FloatVector_append(vec, 0.0);
	FloatVector_append(vec, 1.0);
	FloatVector_print(vec);

	FloatVector_destroy(&vec);

	return (0);
}