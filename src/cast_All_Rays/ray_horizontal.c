/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_horizontal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 13:56:24 by lenox             #+#    #+#             */
/*   Updated: 2020/08/06 17:57:11 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	next_horz_intercept(t_ray *ray, float next_horz_touch_y,
								float next_horz_touch_x)
{
	float	tmp;

	while (next_horz_touch_x >= 0 && next_horz_touch_x <= (g_map_num_cols *
	g_tile_size) && next_horz_touch_y >= 0 && next_horz_touch_y <=
	(g_map_num_rows * g_tile_size))
	{
		tmp = 0;
		if (ray->is_ray_facing_up)
			tmp = 1;
		if (has_wall_at(next_horz_touch_y - tmp, next_horz_touch_x))
		{
			ray->horz_wall_hit_y = next_horz_touch_y;
			ray->horz_wall_hit_x = next_horz_touch_x;
			ray->found_horz_wall_hit = 1;
			return ;
		}
		next_horz_touch_x += ray->xstep;
		next_horz_touch_y += ray->ystep;
	}
}

void		ray_horizontal(t_ray *ray, t_player *player)
{
	float	next_horz_touch_y;
	float	next_horz_touch_x;

	ray->yintercept = floor(player->y / g_tile_size) * g_tile_size;
	if (ray->is_ray_facing_down)
		ray->yintercept += g_tile_size;
	ray->xintercept = player->x + ((ray->yintercept - player->y) /
	tan(ray->ray_angle));
	ray->ystep = g_tile_size;
	if (ray->is_ray_facing_up)
		ray->ystep *= -1;
	ray->xstep = g_tile_size / tan(ray->ray_angle);
	if (ray->is_ray_facing_left && ray->xstep > 0)
		ray->xstep *= -1;
	if (ray->is_ray_facing_right && ray->xstep < 0)
		ray->xstep *= -1;
	next_horz_touch_x = ray->xintercept;
	next_horz_touch_y = ray->yintercept;
	next_horz_intercept(ray, next_horz_touch_y, next_horz_touch_x);
}
