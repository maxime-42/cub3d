/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_wall_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 10:39:59 by lenox             #+#    #+#             */
/*   Updated: 2020/08/07 12:50:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			has_wall_at(float y, float x)
{
	int		mapgridindexx;
	int		mapgridindexy;

	if (x < 0 || x > (g_map_num_cols * g_tile_size) ||
	y < 0 || y > (g_map_num_rows * g_tile_size))
	{
		return (1);
	}
	mapgridindexx = floor(x / g_tile_size);
	mapgridindexy = floor(y / g_tile_size);
	return (g_map[mapgridindexy][mapgridindexx] == '1');
}
