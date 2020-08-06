/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:52:42 by lenox             #+#    #+#             */
/*   Updated: 2020/08/06 18:03:26 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	draw_map_utile(int *ly, int *lx, int j, int color)
{
	int	y;
	int	x;

	y = -1;
	while (++y < g_tile_size * MINIMAP_SCALE_FACTOR)
	{
		x = -1;
		while (++x < g_tile_size * MINIMAP_SCALE_FACTOR)
		{
			g_image_data[*ly * g_window_width + *lx] = color;
			*lx += 1;
		}
		*ly += 1;
		*lx = j * g_tile_size * MINIMAP_SCALE_FACTOR;
	}
}

static	void	draw_map(char **map)
{
	int			y;
	int			x;
	int			lx;
	int			ly;

	y = -1;
	while (++y < g_map_num_rows)
	{
		x = -1;
		while (++x < g_map_num_cols)
		{
			if (map[y][x] == '2' || map[y][x] == '0' ||
			ft_strchr("NSEW", map[y][x]))
			{
				lx = x * g_tile_size * MINIMAP_SCALE_FACTOR;
				ly = y * g_tile_size * MINIMAP_SCALE_FACTOR;
				if (map[y][x] == '2')
					draw_map_utile(&ly, &lx, x, 0xFF0000);
				else
					draw_map_utile(&ly, &lx, x, 0xFFFFFF);
			}
		}
	}
}

static void		player_rect(int cor_x, int cor_y, int width, int height)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < height)
	{
		while (j < width)
		{
			g_image_data[(i + cor_y - width / 2) * g_window_width +
			(j + cor_x - height / 2)] = 0x0078FF;
			j++;
		}
		j = 0;
		i++;
	}
}

static void		orientation_line(int cor_y, int cor_x,
				float distance, float angle)
{
	float		i;
	int			x;
	int			y;
	int			longeur;

	longeur = 0;
	i = 0;
	x = 0;
	y = 0;
	while (i < distance)
	{
		g_image_data[(cor_y + y) * g_window_width + (cor_x + x)] = 0xff0000;
		x = cos(angle) * longeur;
		y = sin(angle) * longeur;
		longeur++;
		i++;
	}
}

void			mini_map(t_player *player, char **map)
{
	draw_map(map);
	player_rect(player->x * MINIMAP_SCALE_FACTOR, player->y *
	MINIMAP_SCALE_FACTOR, player->radius, player->radius);
	orientation_line(player->y * MINIMAP_SCALE_FACTOR,
	player->x * MINIMAP_SCALE_FACTOR,
	10, player->rotation_angle);
}
