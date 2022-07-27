/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_com_mytime.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 06:42:40 by rlins             #+#    #+#             */
/*   Updated: 2022/07/26 19:38:55 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/float_vector.h"
#include "../include/mytime.h"
#include <stdio.h>

int main() {
	FloatVector *vec = FloatVector_create(2);
	FloatVector_print(vec);

	timer t1 = tic();
	FloatVector_append(vec, 0.0);
	FloatVector_append(vec, 1.0);
	FloatVector_print(vec);
	timer t2 = tac();
	printf("Tempo de processamento: %f ms\n", comptime(t1, t2));

	FloatVector_destroy(&vec);

	return (0);
}