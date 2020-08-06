/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_vertical.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 14:04:24 by lenox             #+#    #+#             */
/*   Updated: 2020/08/06 17:57:36 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	next_vert_intercept(t_ray *ray, float next_vert_touch_y,
								float next_vert_touch_x)
{
	float	tmp;

	while (next_vert_touch_x >= 0 && next_vert_touch_x <= g_window_width
	&& next_vert_touch_y >= 0 && next_vert_touch_y <= g_window_height)
	{
		tmp = 0;
		if (ray->is_ray_facing_left)
			tmp = 1;
		if (has_wall_at(next_vert_touch_y, next_vert_touch_x - tmp))
		{
			ray->found_vert_wall_hit = 1;
			ray->vert_wall_hit_x = next_vert_touch_x;
			ray->vert_wall_hit_y = next_vert_touch_y;
			return ;
		}
		next_vert_touch_x += ray->xstep;
		next_vert_touch_y += ray->ystep;
	}
}

void		ray_vertical(t_ray *ray, t_player *player)
{
	float	next_vert_touch_x;
	float	next_vert_touch_y;

	ray->xintercept = floor(player->x / g_tile_size) * g_tile_size;
	if (ray->is_ray_facing_right)
		ray->xintercept += g_tile_size;
	ray->yintercept = player->y + (ray->xintercept - player->x) *
	tan(ray->ray_angle);
	ray->xstep = g_tile_size;
	if (ray->is_ray_facing_left)
		ray->xstep *= -1;
	ray->ystep = g_tile_size * tan(ray->ray_angle);
	if (ray->is_ray_facing_up && ray->ystep > 0)
		ray->ystep *= -1;
	if (ray->is_ray_facing_down && ray->ystep < 0)
		ray->ystep *= -1;
	next_vert_touch_x = ray->xintercept;
	next_vert_touch_y = ray->yintercept;
	next_vert_intercept(ray, next_vert_touch_y, next_vert_touch_x);
}
