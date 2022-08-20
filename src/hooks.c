/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 08:10:37 by rlins             #+#    #+#             */
/*   Updated: 2022/08/19 19:19:11 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/**
 * @brief Hooks looks like a trigger.
 * This method will handler the hooks in project.
 * @param game 
 */
void	hooks_handler(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, exit_game, game); // TODO: Precisa deste cara?
	mlx_hook(game->win, FocusIn, FocusChangeMask, map_draw_img, game); // TODO: Precisa deste cara?
}
