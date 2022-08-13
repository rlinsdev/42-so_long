/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 08:10:37 by rlins             #+#    #+#             */
/*   Updated: 2022/08/13 09:11:34 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	hooks_handler(t_game *game)
{
	printf("\nEntrou no Hooks\n");
	// TODO: Entender o que são estas setinhas <<
	// mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, key_press, game);
	// mlx_hook(game->win, 17, 1L << 17, exit_game, game); // TODO: Precisa deste cara?
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, exit_game, game); // TODO: Precisa deste cara?
	// mlx_hook(game->win, 9, 1L << 21, map_draw, game);
}