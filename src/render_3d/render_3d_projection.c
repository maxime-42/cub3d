/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 14:58:05 by lenox             #+#    #+#             */
/*   Updated: 2020/08/06 17:21:01 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	choice_of_texture(t_ray *ray)
{
	if (ray->isRayFacingUp && !ray->wasHitVertical)
		return (0);
	if (ray->isRayFacingDown && !ray->wasHitVertical)
		return (1);
	if (ray->isRayFacingLeft && ray->wasHitVertical)
		return (2);
	if (ray->isRayFacingRight && ray->wasHitVertical)
		return (3);
	(void)ray;
	return (0);
}

static void	draw_ceiling(t_wall *wall, int column_id)
{
	int	top;
	int	color;

	top = 0;
	color = g_info->color_ceiling;
	while (top < wall->wallTop)
	{
		g_image_data[top * g_window_width + column_id] = color;
		top++;
	}
}

static void	draw_floor(t_wall *wall, int column_id)
{
	int	bottom;
	int	color;

	color = g_info->color_floor;
	bottom = (int)wall->wallBottom;
	while (bottom < g_window_height)
	{
		g_image_data[(bottom * g_window_width) + column_id] = color;
		bottom++;
	}
}

static void	draw_wall(t_ray *ray, t_wall *wall, int column_id)
{
	int	texture_offset_x;
	int	texture_offset_y;
	int	texture_color;
	int	distance_from_top;
	int	index;

	index = choice_of_texture(ray);
	if (ray->wasHitVertical == 1)
		texture_offset_x = (int)(ray->wall_hit_y * g_texture[index].width /
		g_tile_size) % g_texture[index].width;
	else
		texture_offset_x = (int)(ray->wall_hit_x * g_texture[index].width /
		g_tile_size) % g_texture[index].width;
	while (wall->wallTop < wall->wallBottom)
	{
		distance_from_top = wall->wallTop + (wall->wallStripHeight / 2) -
		(g_window_height / 2);
		texture_offset_y = distance_from_top * ((float)g_texture[index].height /
		wall->wallStripHeight);
		texture_color = g_texture[index].wallTexture[(g_texture[index].width *
		texture_offset_y) + texture_offset_x];
		g_image_data[(wall->wallTop * g_window_width) +
		column_id] = texture_color;
		wall->wallTop++;
	}
}

void		render3d_projection(t_ray *ray, int column_id, t_sprite *sprite)
{
	t_wall	wall;

	wall.correctWallDistance = ray->distance * cos(ray->rayAngle -
	g_player.rotationAngle);
	sprite->buffer[column_id] = wall.correctWallDistance;
	wall.distanceProjectionPlane = (g_window_width / 2) / tan(g_fov_angle / 2);
	wall.wallStripHeight = (g_tile_size / wall.correctWallDistance) *
	wall.distanceProjectionPlane;
	wall.wallTop = (g_window_height / 2) - (wall.wallStripHeight / 2);
	if (wall.wallTop < 0)
		wall.wallTop = 0;
	wall.wallBottom = (g_window_height / 2) + (wall.wallStripHeight / 2);
	if (wall.wallBottom > g_window_height)
		wall.wallBottom = g_window_height;
	draw_ceiling(&wall, column_id);
	draw_wall(ray, &wall, column_id);
	draw_floor(&wall, column_id);
}
