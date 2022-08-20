/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:09:41 by rlins             #+#    #+#             */
/*   Updated: 2022/08/20 16:27:54 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	press_a(t_game *game)
{
	// Update Person position
	game->x_player -= 1;
	press_key(game, A_KEY_CONST);
}

void	press_s(t_game *game)
{
	// Update Person position
	game->y_player += 1;
	press_key(game, S_KEY_CONST);
}

void	press_d(t_game *game)
{
	// Update Person position
	game->x_player += 1;
	press_key(game, D_KEY_CONST);
}

void	press_w(t_game *game)
{
	// Update Person position
	game->y_player -= 1;
	press_key(game, W_KEY_CONST);
}

void	person_rollback(t_game *game, char key)
{
	if (key == W_KEY_CONST)
		game->y_player += 1;
	else if (key == A_KEY_CONST)
		game->x_player += 1;
	else if (key == D_KEY_CONST)
		game->x_player -= 1;
	else if (key == S_KEY_CONST)
		game->y_player -= 1;
}
