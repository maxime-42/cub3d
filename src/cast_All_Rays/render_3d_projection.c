/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 14:58:05 by lenox             #+#    #+#             */
/*   Updated: 2020/08/07 12:06:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	choice_of_texture(t_ray *ray)
{
	if (ray->is_ray_facing_up && !ray->was_hit_vertical)
		return (0);
	if (ray->is_ray_facing_down && !ray->was_hit_vertical)
		return (1);
	if (ray->is_ray_facing_left && ray->was_hit_vertical)
		return (2);
	if (ray->is_ray_facing_right && ray->was_hit_vertical)
		return (3);
	(void)ray;
	return (0);
}

static void	draw_wall(t_ray *ray, t_wall *wall, int column_id)
{
	int	texture_offset_x;
	int	texture_offset_y;
	int	texture_color;
	int	distance_from_top;
	int	index;

	index = choice_of_texture(ray);
	if (ray->was_hit_vertical == 1)
		texture_offset_x = (int)(ray->wall_hit_y * g_texture[index].width /
		g_tile_size) % g_texture[index].width;
	else
		texture_offset_x = (int)(ray->wall_hit_x * g_texture[index].width /
		g_tile_size) % g_texture[index].width;
	while (wall->wall_top < wall->wall_bottom)
	{
		distance_from_top = wall->wall_top + (wall->wall_strip_height / 2) -
		(g_window_height / 2);
		texture_offset_y = distance_from_top * ((float)g_texture[index].height /
		wall->wall_strip_height);
		texture_color = g_texture[index].wall_texture[(g_texture[index].width *
		texture_offset_y) + texture_offset_x];
		g_image_data[(wall->wall_top * g_window_width) +
		column_id] = texture_color;
		wall->wall_top++;
	}
}

void		render3d_projection(t_ray *ray, int column_id, t_sprite *sprite)
{
	t_wall	wall;

	wall.correct_wall_distance = ray->distance * cos(ray->ray_angle -
	g_player.rotation_angle);
	sprite->buffer[column_id] = wall.correct_wall_distance;
	wall.distance_projection_plane = (g_window_width / 2) /
	tan(g_fov_angle / 2);
	wall.wall_strip_height = (g_tile_size / wall.correct_wall_distance) *
	wall.distance_projection_plane;
	wall.wall_top = (g_window_height / 2) - (wall.wall_strip_height / 2);
	if (wall.wall_top < 0)
		wall.wall_top = 0;
	wall.wall_bottom = (g_window_height / 2) + (wall.wall_strip_height / 2);
	if (wall.wall_bottom > g_window_height)
		wall.wall_bottom = g_window_height;
	/* ft_ceiling(); */
	/* draw_ceiling(&wall, column_id); */
	/* draw_floor(&wall, column_id); */
	draw_wall(ray, &wall, column_id);	
	/* ft_floor(); */	
}
