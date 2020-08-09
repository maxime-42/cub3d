/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:10:25 by lenox             #+#    #+#             */
/*   Updated: 2020/08/09 14:08:41 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H
# include "cub3d.h"

int		key_pressed(int keycode);
int		get_file_descriptor(t_info *info, char *name_file);
void	get_positionplayer(char **map, int *y, int *x);
int		key_release(int keycode);
float	distance_between_points(float x1, float y1, float x2, float y2);
void	player_movement(t_player *player);
void	init_player(t_player *player);
void	drawline(int cory, int corx, float distance, int color, float angle);
void	drawrect(int corx, int cory, int width, int height, int color);
void	cast_all_rays(t_player *player, t_ray *ray, t_sprite *sprite);
void	ray_horizontal(t_ray *ray, t_player *player);
void	ray_vertical(t_ray *ray, t_player *player);
void	render3d_projection(t_ray *ray, int columnid, t_sprite *sprite);
void	put_sprite(t_ray *ray, int top, int wallstripheight,
		int wallbottom, int columnid);
void	playerposition(t_player *player);
float	normalize_angle(float angle);
void	bmp_exporter(char *file_name);
void	mini_map(t_player *player, char **map);
void	init_mlx_and_window(void *mlx_ptr, void *win_mlx, char *filename);
int		count_sprite(char **map);
void	ft_mallocsprite(t_sprite *sprite);
void	ft_putsprite(t_sprite *sprite, t_player *player);
void	ft_putsprite(t_sprite *sprite, t_player *player);
void	init_sprite(t_sprite *sprite, char **map, char player_position);
int		get_path_sprite(int fd, t_sprite *sprite);
void	handling_event(t_info *info);
int		game_loop(t_info *info);
int		ft_spritevisible(t_sprite *sprite, t_player *player,
		int id, float sprite_size);
float	ft_calculangle(t_player *player, float x, float y);
void	ft_getstart(t_sprite *sprite, float sprite_size, float transformy);
void	ft_drawsprite(t_sprite *sprite, float transformy, float sprite_size);
void	ft_puttexture(t_sprite *sprite, int x, int y, float sprite_size);
int		has_wall_at(float y, float x);
int		close_window(int keycode);
void	init_vecteur_north(t_sprite *sprite);
void	ft_spritedistance(t_sprite *sprite, t_player *player);
void	draw_floor(void);
void	draw_ceiling(void);
#endif
