/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 14:44:41 by lenox             #+#    #+#             */
/*   Updated: 2020/08/06 18:04:20 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	init_struct_ray(t_ray *ray)
{
	ray->xintercept = 0;
	ray->yintercept = 0;
	ray->xstep = 0;
	ray->ystep = 0;
	ray->wall_hit_x = 0;
	ray->wall_hit_y = 0;
	ray->was_hit_vertical = 0;
	ray->vert_wall_hit_x = 0;
	ray->vert_wall_hit_y = 0;
	ray->horz_wall_hit_y = 0;
	ray->horz_wall_hit_x = 0;
	ray->found_vert_wall_hit = 0;
	ray->found_horz_wall_hit = 0;
	ray->is_ray_facing_down = 0;
	ray->is_ray_facing_up = 0;
	ray->is_ray_facing_right = 0;
	ray->is_ray_facing_left = 0;
	ray->distance = 0;
}

static	void	ray_facing(t_ray *ray)
{
	if (ray->ray_angle > 0 && ray->ray_angle < M_PI)
		ray->is_ray_facing_down = 1;
	else
		ray->is_ray_facing_up = 1;
	if (ray->ray_angle < (0.5 * M_PI) || ray->ray_angle > (1.5 * M_PI))
		ray->is_ray_facing_right = 1;
	else
		ray->is_ray_facing_left = 1;
}

static	void	the_smallest_of_the_distances_utile(t_ray *ray,
				float vert_hit_distance, float horz_hit_distance)
{
	if (horz_hit_distance < vert_hit_distance)
	{
		ray->wall_hit_x = ray->horz_wall_hit_x;
		ray->wall_hit_y = ray->horz_wall_hit_y;
		ray->distance = horz_hit_distance;
	}
	else
	{
		ray->wall_hit_x = ray->vert_wall_hit_x;
		ray->wall_hit_y = ray->vert_wall_hit_y;
		ray->distance = vert_hit_distance;
	}
	if (vert_hit_distance < horz_hit_distance)
		ray->was_hit_vertical = 1;
}

static void		the_smallest_of_the_distances(t_ray *ray, t_player *player)
{
	float		horz_hit_distance;
	float		vert_hit_distance;

	horz_hit_distance = 0;
	vert_hit_distance = 0;
	if (ray->found_horz_wall_hit == 1)
		horz_hit_distance = distance_between_points(player->x, player->y,
		ray->horz_wall_hit_x, ray->horz_wall_hit_y);
	else
		horz_hit_distance = MAX_VALUE;
	if (ray->found_vert_wall_hit == 1)
		vert_hit_distance = distance_between_points(player->x, player->y,
		ray->vert_wall_hit_x, ray->vert_wall_hit_y);
	else
		vert_hit_distance = MAX_VALUE;
	the_smallest_of_the_distances_utile(ray,
	vert_hit_distance, horz_hit_distance);
}

void			cast_all_rays(t_player *player, t_ray *ray, t_sprite *sprite)
{
	int			column_id;

	column_id = 0;
	ray->ray_angle = g_player.rotation_angle - (g_fov_angle / 2);
	while (column_id < g_num_rays)
	{
		ray->ray_angle = normalize_angle(ray->ray_angle);
		init_struct_ray(ray);
		ray_facing(ray);
		ray_horizontal(ray, player);
		ray_vertical(ray, player);
		the_smallest_of_the_distances(ray, player);
		render3d_projection(ray, column_id, sprite);
		ray->ray_angle += (g_fov_angle / g_num_rays);
		column_id++;
	}
	(void)player;
	(void)ray;
}
