/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 08:06:03 by rlins             #+#    #+#             */
/*   Updated: 2022/08/13 10:45:40 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	void handle_keys(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_Up)
	{
		printf("\nw apertado - %d\n", keycode);
		game->moves++;
	}
	else if (keycode == XK_a || keycode == XK_Left)
	{
		printf("\na apertado - %d\n", keycode);
		game->moves++;
	}
	else if (keycode == XK_s || keycode == XK_Down)
	{
		printf("\ns apertado - %d\n", keycode);
		game->moves++;
	}
	else if (keycode == XK_d || keycode == XK_Right)
	{
		printf("\nd apertado - %d\n", keycode);
		game->moves++;
	}
}

int	key_press(int keycode, t_game *game)
{
	printf("\nEntrou no Key Press");
	//if (keycode == KEY_ESC || keycode == KEY_Q)
	if (keycode == XK_Escape)
		exit_game(game);
	else 
	{
		handle_keys(keycode, game);
		printf("Number of Movements: %d", game->moves);
	}
	return (0);
}
