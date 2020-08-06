/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:09:43 by lenox             #+#    #+#             */
/*   Updated: 2020/08/06 17:10:02 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H
# include "struct.h"

t_info			*g_info;
t_texture		g_texture[4];
t_player		g_player;
void			*g_mlx_ptr;
void			*g_img_ptr;
void			*g_win_mlx;
int				*g_image_data;
int				g_screen_width;
int				g_screen_height;
char			**g_map;
t_ray			g_ray;
t_sprite		g_sprite;
int				g_wall_strip_width;
int				g_tile_size;
int				g_map_num_rows;
int				g_map_num_cols;
int				g_window_width;
int				g_window_height;
float			g_num_rays;
float			g_fov_angle;

#endif
