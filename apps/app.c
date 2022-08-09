/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:55:06 by rlins             #+#    #+#             */
/*   Updated: 2022/08/09 06:53:26 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/so_long.h"

// int	main(int argc, char **argv) 
// {
// 	start(argc, argv);
// }


// *--* INICIO harm-smits INICIO  *--*

// // *--* INICIO Exemplo 1 - Initialize MiniLibX
// #include "../include/so_long.h"

// int	main(void)
// {
// 	void	*mlx;

// 	mlx = mlx_init();
// 	printf("oi oi io \n");
// }
// // *--* FIM Exemplo 1 - Initialize MiniLibX

// *--* INICIO Exemplo 2 - Open Window
#include "../include/so_long.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}
// *--* FIM Exemplo 2 - Open Window

// #include "../include/so_long.h"
// int	main(void)
// {
// 	void	*img;
// 	void	*mlx;

// 	mlx = mlx_init();
// 	img = mlx_new_image(mlx, 1920, 1080);
// }

// *--* FIM harm-smits INICIO  *--*

//oioioi