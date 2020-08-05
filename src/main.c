#include "cub3d.h"

static	void	createImage(void *mlx_ptr, void *img_ptr, void *image_data)
{
	int	bpp;
	int	size_line;
	int	endian;

	img_ptr = 0;
	endian = 0;
	if (!(img_ptr = mlx_new_image(mlx_ptr, g_window_width, g_window_height)))
	{
		ft_putstr_fd("Error\nfaile to get image pointer", STDOUT);
		freeAll(ERROR);
	}
	image_data = (int *)mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	if (!image_data)
	{
		ft_putstr_fd("Error\nfaile to get image data", STDOUT);
		freeAll(ERROR);
		exit(ERROR);
	}
	g_img_ptr = img_ptr;
	g_image_data = image_data;
}

int	game_loop(t_info *info)
{
	t_ray	ray;

	createImage(g_mlx_ptr, g_img_ptr, g_image_data);
	playerMovement(&g_player);
	ft_putsprite(&g_sprite, &g_player);
	cast_All_Rays(&g_player, &ray, &g_sprite);
	miniMap(&g_player, g_info->map);
	ft_putsprite(&g_sprite, &g_player);
	if (g_info->screenshoot)
		bmp_exporter("my_screenshoot");
	else
	{
		mlx_put_image_to_window(g_mlx_ptr, g_win_mlx, g_img_ptr, 0, 0);
		mlx_destroy_image (g_mlx_ptr, g_img_ptr);
		g_img_ptr = 0;
	}
	(void)info;
	return (SUCCESS);
}

static void	init_global_variable()
{
  	g_map = (char **)g_info->map;
	/* g_map_num_rows = g_info->height; */
	/* g_map_num_cols =  (int)ft_strlen(g_info->begin->content); */
	/* g_map_num_cols =  (int)ft_strlen(g_info->begin->content); */
	g_map_num_cols =  g_info->column;
	g_texture[0].texture_ptr = 0;
	g_wall_strip_width = 1;
	g_window_width = g_screen_width;
	g_window_height = g_screen_height;
	g_tile_size = (g_window_width / g_map_num_cols);
	/* g_window_width = (g_map_num_cols * g_tile_size); */
	/* g_window_height = (g_map_num_rows * g_tile_size); */
	g_num_rays = (g_window_width / g_wall_strip_width);
	g_fov_angle = (60 * (M_PI / 180));
}

static void	load_ptr_textures_in_array(t_texture texture[NUM_TEXTURE])
{
	int	bpp;
	int	size_line;
	int	endian;
	int	i;

	i = -1;
	while (++i < NUM_TEXTURE)
	{
		texture[i].texture_ptr = mlx_xpm_file_to_image(g_mlx_ptr, texture[i].path, &texture[i].width, &texture[i].height);
		if (!texture[i].texture_ptr)
		{
			ft_putstr_fd("Error\nFailer texture ptr\n", STDOUT);
			exit (freeAll(ERROR));
		}
		texture[i].wallTexture = (int *)mlx_get_data_addr(texture[i].texture_ptr, &bpp, &size_line, &endian);
		if (!texture[i].wallTexture)
		{
			ft_putstr_fd("Error\nFailer texture ptr\n", STDOUT);
			exit (freeAll(ERROR));
		}
	}
}

void			*init_mlx(void)
{
	void		*mlx_ptr;

	g_mlx_ptr = 0;
	if (!(mlx_ptr = mlx_init()))
	{
		ft_putstr_fd("Error\nfaile init mlx\n", STDOUT);
		exit(freeAll(ERROR));
	}
	return (mlx_ptr);
}

void	*createWindow(void *mlx_ptr)
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
		if (!(win_mlx = mlx_new_window(mlx_ptr, g_screen_width, g_screen_height, "3D")))
		{
			ft_putstr_fd("Error\nfaile open window\n", STDOUT);
			exit(freeAll(ERROR));
		}
	}
	return (win_mlx);
}

void	check_argument(t_info *info, int nb_arg, char **arg_array)
{
	info->screenshoot = 0;
	if (nb_arg == 3)
	{
		if (!ft_strcmp("--save", arg_array[2]))
		{
			info->screenshoot = 1;
			if (check_file_extension(arg_array[1], ".cub") == ERROR)
				exit(ERROR);
		}
		else
		{
			ft_putstr_fd("Error\nwrong argument\n", STDOUT);
			exit(ERROR);
		}
	}
	else if (nb_arg != 2)
	{
		ft_putstr_fd("Error\nwrong argument\n", STDOUT);
		exit(ERROR);
	}
	if (nb_arg == 2)
	{
					/* printf("arg_array[1] %s\n", arg_array[1]); */
		if (check_file_extension(arg_array[1], ".cub") == ERROR)
			exit(ERROR);
	}
}

int		main(int ac, char **av)
{
	t_info	info;

	info.map = 0;
	g_sprite.ptr = 0;
	g_info = &info;
	g_texture[0].texture_ptr = 0;
	/* if (ac == 3) */
	/* { */
	/* 	if (!ft_strcmp("--save", av[2])) */
	/* 		filename = "myscreenShoot"; */
	/* 	else */
	/* 	{ */
	/* 		ft_putstr_fd("Error\nwrong argument\n", STDOUT); */
	/* 		return (ERROR); */
	/* 	} */
	/* } */
	/* else if (ac != 2) */
	/* { */
	/* 	ft_putstr_fd("Error\nwrong argument\n", STDOUT); */
	/* 	return (ERROR); */
	/* } */
	/* g_info->screenshoot = 0; */
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
	g_win_mlx = createWindow(g_mlx_ptr);
	if (!info.screenshoot)
		handling_event(&info);
	else
	{
		game_loop(&info);
	}
	/* if (!filename) */
	/* 	handling_event(&info); */
	/* else */
	/* { */
	/* 	game_loop(&info); */
	/* } */
	return (freeAll(SUCCESS));
}
