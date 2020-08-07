/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:07:47 by lenox             #+#    #+#             */
/*   Updated: 2020/08/07 15:04:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	create_image(void *mlx_ptr, void *img_ptr, void *image_data)
{
	int			bpp;
	int			size_line;
	int			endian;

	img_ptr = 0;
	endian = 0;
	if (!(img_ptr = mlx_new_image(mlx_ptr, g_window_width, g_window_height)))
	{
		ft_putstr_fd("Error\nfaile to get image pointer", STDOUT);
		free_all(ERROR);
	}
	image_data = (int *)mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	g_size = size_line;
	if (!image_data)
	{
		ft_putstr_fd("Error\nfaile to get image data", STDOUT);
		free_all(ERROR);
		exit(ERROR);
	}
	g_img_ptr = img_ptr;
	g_image_data = image_data;
}

int				game_loop(t_info *info)
{
	t_ray		ray;

	create_image(g_mlx_ptr, g_img_ptr, g_image_data);
	player_movement(&g_player);
	draw_ceiling();
	draw_floor();
	ft_putsprite(&g_sprite, &g_player);
	cast_all_rays(&g_player, &ray, &g_sprite);
	mini_map(&g_player, g_info->map);
	ft_putsprite(&g_sprite, &g_player);
	if (g_info->screenshoot)
		bmp_exporter("my_screenshoot.bmp");
	else
	{
		mlx_put_image_to_window(g_mlx_ptr, g_win_mlx, g_img_ptr, 0, 0);
		mlx_destroy_image(g_mlx_ptr, g_img_ptr);
		g_img_ptr = 0;
	}
	(void)info;
	return (SUCCESS);
}

void			*init_mlx(void)
{
	void		*mlx_ptr;

	g_mlx_ptr = 0;
	if (!(mlx_ptr = mlx_init()))
	{
		ft_putstr_fd("Error\nfaile init mlx\n", STDOUT);
		exit(free_all(ERROR));
	}
	return (mlx_ptr);
}

void			*create_window(void *mlx_ptr)
{
	int			width;
	int			height;
	void		*win_mlx;

	mlx_get_screen_size(mlx_ptr, &width, &height);
	if (g_screen_width > width)
		g_screen_width = width;
	if (g_screen_height > height)
		g_screen_height = height;
	win_mlx = 0;
	if (!g_info->screenshoot)
	{
		if (!(win_mlx = mlx_new_window(mlx_ptr, g_screen_width,
		g_screen_height, "3D")))
		{
			ft_putstr_fd("Error\nfaile open window\n", STDOUT);
			exit(free_all(ERROR));
		}
	}
	return (win_mlx);
}

int				main(int ac, char **av)
{
	t_info		info;

	info.map = 0;
	g_sprite.ptr = 0;
	g_info = &info;
	g_texture[0].texture_ptr = 0;
	check_argument(&info, ac, av);
	if (get_file_descriptor(&info, av[1]) == ERROR)
		return (ERROR);
	if (parsing(&info) == ERROR)
		return (ERROR);
	g_mlx_ptr = init_mlx();
	load_ptr_textures_in_array(g_texture);
	init_global_variable();
	init_player(&g_player);
	init_sprite(&g_sprite, g_map, g_player.position);
	g_win_mlx = create_window(g_mlx_ptr);
	if (!info.screenshoot)
		handling_event(&info);
	else
	{
		game_loop(&info);
	}
	return (free_all(SUCCESS));
}
