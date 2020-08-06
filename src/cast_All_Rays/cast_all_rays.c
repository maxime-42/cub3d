/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 14:44:41 by lenox             #+#    #+#             */
/*   Updated: 2020/08/06 17:19:18 by lenox            ###   ########.fr       */
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
	ray->wasHitVertical = 0;
	ray->vertWallHitX = 0;
	ray->vertWallHitY = 0;
	ray->horzWallHitY = 0;
	ray->horzWallHitX = 0;
	ray->foundVertWallHit = 0;
	ray->foundHorzWallHit = 0;
	ray->isRayFacingDown = 0;
	ray->isRayFacingUp = 0;
	ray->isRayFacingRight = 0;
	ray->isRayFacingLeft = 0;
	ray->distance = 0;
}

static	void	ray_facing(t_ray *ray)
{
	if (ray->rayAngle > 0 && ray->rayAngle < M_PI)
		ray->isRayFacingDown = 1;
	else
		ray->isRayFacingUp = 1;
	if (ray->rayAngle < (0.5 * M_PI) || ray->rayAngle > (1.5 * M_PI))
		ray->isRayFacingRight = 1;
	else
		ray->isRayFacingLeft = 1;
}

static	void	the_smallest_of_the_distances_utile(t_ray *ray,
				float vert_hit_distance, float horz_hit_distance)
{
	if (horz_hit_distance < vert_hit_distance)
	{
		ray->wall_hit_x = ray->horzWallHitX;
		ray->wall_hit_y = ray->horzWallHitY;
		ray->distance = horz_hit_distance;
	}
	else
	{
		ray->wall_hit_x = ray->vertWallHitX;
		ray->wall_hit_y = ray->vertWallHitY;
		ray->distance = vert_hit_distance;
	}
	if (vert_hit_distance < horz_hit_distance)
		ray->wasHitVertical = 1;
}

static void		the_smallest_of_the_distances(t_ray *ray, t_player *player)
{
	float		horz_hit_distance;
	float		vert_hit_distance;

	horz_hit_distance = 0;
	vert_hit_distance = 0;
	if (ray->foundHorzWallHit == 1)
		horz_hit_distance = distance_between_points(player->x, player->y,
		ray->horzWallHitX, ray->horzWallHitY);
	else
		horz_hit_distance = MAX_VALUE;
	if (ray->foundVertWallHit == 1)
		vert_hit_distance = distance_between_points(player->x, player->y,
		ray->vertWallHitX, ray->vertWallHitY);
	else
		vert_hit_distance = MAX_VALUE;
	the_smallest_of_the_distances_utile(ray,
	vert_hit_distance, horz_hit_distance);
}

void			cast_all_rays(t_player *player, t_ray *ray, t_sprite *sprite)
{
	int			column_id;

	column_id = 0;
	ray->rayAngle = g_player.rotationAngle - (g_fov_angle / 2);
	while (column_id < g_num_rays)
	{
		ray->rayAngle = normalize_angle(ray->rayAngle);
		init_struct_ray(ray);
		ray_facing(ray);
		ray_horizontal(ray, player);
		ray_vertical(ray, player);
		the_smallest_of_the_distances(ray, player);
		render3d_projection(ray, column_id, sprite);
		ray->rayAngle += (g_fov_angle / g_num_rays);
		column_id++;
	}
	(void)player;
	(void)ray;
}
