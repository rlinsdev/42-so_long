/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:07:31 by rlins             #+#    #+#             */
/*   Updated: 2022/08/18 20:28:45 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	player_update_image(t_game *game, char key)
{
	if(key == 'a' || key == 'd')
	{
		mlx_destroy_image(game->mlx, game->img_player);
		if (key == 'd')
			game->img_player = mlx_xpm_file_to_image(game->mlx, "img/p.xpm", &game->img_w, &game->img_h);
		else if (key == 'a')
			game->img_player = mlx_xpm_file_to_image(game->mlx, "img/pa.xpm", &game->img_w, &game->img_h);
	}
}

static void	update_x_axio(t_game *game, char key)
{
	if (key == 'a')
		game->map[game->y_player][game->x_player + 1] = '0';
	else if (key = 'd')
		game->map[game->y_player][game->x_player - 1] = '0';
}

static	void update_y_axio(t_game *game, char key)
{
	if (key == 'w')
		game->map[game->y_player + 1][game->x_player] = '0';
	else if (key == 's')
		game->map[game->y_player - 1][game->x_player] = '0';
}

static void person_stop(t_game *game, char key)
{
	if (key == 'w')
		game->y_player += 1;
	else if (key == 'a')
		game->x_player += 1;
	else if (key == 'd')
		game->x_player -= 1;
	else if (key == 's')
		game->y_player -= 1;
}

static void person_walk(t_game *game, char key)
{
	if(key == 'w' || key == 's')
		update_y_axio(game, key);
	else if (key == 'a' || key == 'd')
		update_x_axio(game, key);
}

static void	press_key(t_game *game, char key)
{
	player_update_image(game, key);

	// No More Collectons, and is exit
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->n_collectible == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		//game->map[game->y_player + 1][game->x_player] = '0';
		person_walk(game, key);
		game->moves++;
		game->endgame = 1;
		map_draw_img(game);
	}
	// If you try hit a Wall or exit without collect all, it's not allow
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		person_stop(game, key);
	else
	{
		mlx_clear_window(game->mlx, game->win);
		// Decrement collectable, if this is the type
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_collectible -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		person_walk(game, key);
		game->moves++;
		map_draw_img(game);
	}
}

void	press_a(t_game *game)
{
	ft_printf("\nLetra a\n");
	press_key(game, 'a');
}

void	press_s(t_game *game)
{
	ft_printf("\nLetra s\n");
	press_key(game, 's');
}

void	press_d(t_game *game)
{
	ft_printf("\nLetra d\n");
	press_key(game, 'd');
}

void	press_w(t_game *game)
{
	ft_printf("\nLetra w\n");
	press_key(game, 'w');
}