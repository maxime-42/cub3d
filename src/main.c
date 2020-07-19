#include "cub3d.h"

char	*filename = 0;

static	void	createImage(void *mlx_ptr, void *img_ptr, void *image_data)
{
	int			bpp;
	int			size_line;
	int			endian;

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

static int	gameLoop(t_info *info)
{
	t_ray	ray;
	/* int	x; */
	/* int	y; */

	/* mlx_get_screen_size(g_mlx_ptr, &x, &y); */
	/* printf("x = %d\n", x); */
	/* printf("y = %d\n", y); */
	createImage(g_mlx_ptr, g_img_ptr, g_image_data);
	playerMovement(&g_player);
	cast_All_Rays(&g_player, &ray);
	miniMap(&g_player, g_info->map);
	/* drawMap(g_info->map); */
	/* drawPlayer(&g_player); */
	/* cast_All_Rays(&g_player, &g_ray); */
	/* mlx_clear_window(g_mlx_ptr, g_win_mlx); */
	if (filename)
	{
		bmp_exporter(filename);
		freeAll(SUCCESS);
	}
	else
	{
		mlx_put_image_to_window(g_mlx_ptr, g_win_mlx, g_img_ptr, 0, 0);
		mlx_destroy_image (g_mlx_ptr, g_img_ptr);
	}
	///mlx_destroy_image(g_mlx_ptr, g_img_ptr);
	g_img_ptr = 0;
	(void)info;
	return (0);
}

static void		init_global_variable()
{
	g_wall_strip_width = 1;
	g_tile_size = 32;
	g_map_num_rows = g_info->height;
	g_map_num_cols =  (int)ft_strlen(g_info->begin->content);
	g_window_width = (g_map_num_cols * g_tile_size);
	g_window_height = (g_map_num_rows * g_tile_size);
	g_num_rays = (g_window_width / g_wall_strip_width);
	g_fov_angle = (60 * (M_PI / 180));
}

int				main(int ac, char **av)
{
	t_info		info;
	int			keyCode;
	g_mlx_ptr = 0;
	g_win_mlx = 0;
	info.map = 0;
	g_texture[0].texture_ptr = 0;
	g_sprite.ptr = 0;
	g_info = &info;
	if (ac == 3)
		filename = "myscreenShoot";
	else if (ac != 2)
	{
		ft_putstr_fd("Error\nError\nnumber argument\n", STDOUT);
		return (ERROR);
	}
	if (get_file_descriptor(&info, av[1]) == ERROR)
		return (ERROR);
	if (parsing_map(&info) == ERROR)
		return (ERROR);
	init_global_variable();
	init_mlx_and_window(g_mlx_ptr, g_win_mlx, filename);
	/* return (freeAll(SUCCESS)); */
	getTexture(g_texture);
	g_map = (char **)info.map;
	init_player(&g_player);
	/* printf("window_width %d\n", g_window_width); */
	/* printf("WINDOW_WIDTH = %d\n", WINDOW_WIDTH); */
	/* init_sprite(&g_sprite, g_map, g_player.rotationAngle);*/
	if (!filename)
	{
		mlx_hook(g_win_mlx, 2, (1L << 0), &keyPressed, &keyCode);
		mlx_hook(g_win_mlx, 3, (1L << 1), &keyRelease, &keyCode);
		mlx_loop_hook(g_mlx_ptr, &gameLoop, &info);
		mlx_loop(g_mlx_ptr);
	}
	else
		gameLoop(g_info);
	return (freeAll(SUCCESS));
}
