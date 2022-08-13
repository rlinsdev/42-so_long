/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 08:06:03 by rlins             #+#    #+#             */
/*   Updated: 2022/08/13 08:57:00 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_press(int keycode, t_game *game)
{
	printf("\nEntrou no Key Press\n");
	//if (keycode == KEY_ESC || keycode == KEY_Q)
	if (keycode == XK_Escape)
		exit_game(game);
	// else if (!game->endgame)
	// {
	// 	game_events(keycode, game);
	// 	printf("Moves: %d\n", game->moves);
	// }
	return (keycode);
}