/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 08:06:03 by rlins             #+#    #+#             */
/*   Updated: 2022/08/18 08:10:32 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	void handle_keys(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_Up)
	{
		ft_printf("\nw apertado - %d\n", keycode);
		game->y_player -= 1;
		press_w(game);
		game->moves++;
	}
	else if (keycode == XK_a || keycode == XK_Left)
	{
		ft_printf("\na apertado - %d\n", keycode);
		game->x_player -= 1;
		press_a(game);
		game->moves++;
	}
	else if (keycode == XK_s || keycode == XK_Down)
	{
		ft_printf("\ns apertado - %d\n", keycode);
		game->y_player += 1;
		press_s(game);
		game->moves++;
	}
	else if (keycode == XK_d || keycode == XK_Right)
	{
		ft_printf("\nd apertado - %d\n", keycode);
		game->x_player += 1;
		press_d(game);
		game->moves++;
	}
}

int	key_press(int keycode, t_game *game)
{
	ft_printf("\nEntrou no Key Press");
	//if (keycode == KEY_ESC || keycode == KEY_Q)
	if (keycode == XK_Escape)
		exit_game(game);
	else 
	{
		handle_keys(keycode, game);
		ft_printf("Number of Movements: %d", game->moves);
	}
	return (0);
}
