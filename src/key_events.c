/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 08:06:03 by rlins             #+#    #+#             */
/*   Updated: 2022/08/19 13:28:03 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/**
 * @brief Responsable to call a correct press buton method to take action
 * @param keycode KeyCode of keybord pressed
 * @param game Game object
 */
static	void handle_keys(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_Up)
	{
		ft_printf("\nw apertado - %d\n", keycode);
		press_w(game);
	}
	else if (keycode == XK_a || keycode == XK_Left)
	{
		ft_printf("\na apertado - %d\n", keycode);
		press_a(game);
	}
	else if (keycode == XK_s || keycode == XK_Down)
	{
		ft_printf("\ns apertado - %d\n", keycode);
		press_s(game);
	}
	else if (keycode == XK_d || keycode == XK_Right)
	{
		ft_printf("\nd apertado - %d\n", keycode);
		press_d(game);
	}
}

/**
 * @brief Called by Hook key press.
 * Any key pressed in window, will call this function 
 * @param keycode 
 * @param game 
 * @return int. Important to MLX framework return a int
 */
int	key_press(int keycode, t_game *game)
{
	// Exit game when esc
	if (keycode == XK_Escape)
		exit_game(game);
	else if (!game->endgame)
	{
		handle_keys(keycode, game);
		ft_printf("Number of Movements: %d", game->moves);
	}
	// When endgame==1, just stop to take actions
	return (0);
}
