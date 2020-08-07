/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:12:40 by lenox             #+#    #+#             */
/*   Updated: 2020/08/06 18:40:07 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STRUCT_H
# define _STRUCT_H
# define SIZE_PATH 64

typedef struct		s_ray
{
	float			xintercept;
	float			yintercept;
	float			xstep;
	float			ystep;
	float			wall_hit_x;
	float			wall_hit_y;
	float			vert_wall_hit_x;
	float			vert_wall_hit_y;
	float			horz_wall_hit_y;
	float			horz_wall_hit_x;
	float			was_hit_vertical;
	float			ray_angle;
	int				found_vert_wall_hit;
	int				found_horz_wall_hit;
	int				is_ray_facing_down;
	int				is_ray_facing_up;
	int				is_ray_facing_right;
	int				is_ray_facing_left;
	float			distance;
}					t_ray;

typedef struct		s_player
{
	float			x;
	float			y;
	int				radius;
	float			angle_angle;
	int				turn_direction;
	int				walk_direction;
	float			rotation_angle;
	float			move_speed;
	float			rotation_speed;
	char			position;
	int				translation;
}					t_player;

typedef struct		s_info
{
	char			*texture[5];
	int				nline_map;
	int				column;
	int				height;
	char			*sprint;
	void			*map;
	t_list			*begin;
	int				color_ceiling;
	int				color_floor;
	int				fd;
	unsigned int	screenshoot : 1;
	int				size_line;
	char			orientation;
}					t_info;

typedef struct		s_texture
{
	char			*path;
	void			*texture_ptr;
	int				*wall_texture;
	int				height;
	int				width;
}					t_texture;

typedef struct		s_wall
{
	float			correct_wall_distance;
	float			distance_projection_plane;
	int				wall_strip_height;
	int				wall_top;
	int				wall_bottom;
}					t_wall;

typedef struct		s_bmp_file
{
	char			byte_type[2];
	unsigned int	byte_size;
	unsigned int	byte_reserved;
	unsigned int	byte_offset;
	unsigned		header_size;
	int				image_width;
	int				image_height;
	unsigned short	color_planes;
	unsigned short	bits_per_pixel;
	unsigned int	compression;
	unsigned int	image_size;
	int				bits_xpels_per_meter;
	int				bits_ypels_per_meter;
	unsigned int	total_colors;
	unsigned int	important_colors;
}					t_bmp_file;

typedef struct		s_sprite
{
	float			diry;
	float			dirx;
	float			plany;
	float			planx;
	int				*data;
	void			*ptr;
	int				size_l;
	float			*distance;
	float			angle;
	int				width;
	int				bpp;
	int				endian;
	int				height;
	float			*x;
	float			*y;
	char			*path;
	int				nb_sprite;
	float			*buffer;
	int				spritescreenx;
	int				drawstarty;
	int				drawendy;
	int				drawstartx;
	int				drawendx;
}					t_sprite;

#endif
