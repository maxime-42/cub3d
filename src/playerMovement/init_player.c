/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 10:51:48 by lenox             #+#    #+#             */
/*   Updated: 2020/08/06 18:57:54 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		coordinate_player(t_player *player)
{
	int		x;
	int		y;

	y = -1;
	while (g_map[++y])
	{
		x = -1;
		while (g_map[y][++x])
		{
			if (g_map[y][x] == 'N' || g_map[y][x] == 'S' ||
			g_map[y][x] == 'W' || g_map[y][x] == 'E')
			{
				player->x = g_tile_size * x + g_tile_size / 2;
				player->y = g_tile_size * y + g_tile_size / 2;
				player->position = g_map[y][x];
			}
		}
	}
}

static void		player_position(t_player *player)
{
	coordinate_player(player);
	if (player->position == 'N')
		player->rotation_angle = 1.5 * M_PI;
	else if (player->position == 'W')
		player->rotation_angle = M_PI;
	else if (player->position == 'E')
		player->rotation_angle = 0;
	else if (player->position == 'S')
		player->rotation_angle = 0.5 * M_PI;
}

void			init_player(t_player *player)
{
	player->radius = 5;
	player->turn_direction = 0;
	player->walk_direction = 0;
	player_position(player);
	player->move_speed = 1;
	player->rotation_speed = 3 * (M_PI / 180);
}
