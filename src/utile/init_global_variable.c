/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global_variable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:11:29 by lenox             #+#    #+#             */
/*   Updated: 2020/08/06 19:34:42 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_global_variable(void)
{
	g_map = (char **)g_info->map;
	g_map_num_cols = g_info->column;
	g_map_num_rows = g_info->height;
	g_texture[0].texture_ptr = 0;
	g_wall_strip_width = 1;
	g_window_width = g_screen_width;
	g_window_height = g_screen_height;
	g_tile_size = (g_window_width / g_map_num_cols);
	g_num_rays = (g_window_width / g_wall_strip_width);
	g_fov_angle = (60 * (M_PI / 180));
}
