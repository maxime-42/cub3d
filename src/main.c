#include "cub3d.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static	void	createImage(void)
{
	int	bpp;
	int	size_line;
	int	endian;

	g_img_ptr = 0;
	endian = 0;
	if (!(g_img_ptr = mlx_new_image(g_mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT)))
	{
		ft_putstr_fd("Error\nfaile to get image pointer", STDOUT);
		freeAll(ERROR);
		exit(ERROR);
	}
	g_image_data = (int *)mlx_get_data_addr(g_img_ptr, &bpp, &size_line, &endian);
	if (!g_image_data)
	{
		ft_putstr_fd("Error\nfaile to get image data", STDOUT);
		freeAll(ERROR);
		exit(ERROR);
	}
}

static int		gameLoop(t_info *info)
{
	t_ray ray;
	/* int	x; */
	/* int	y; */

	/* mlx_get_screen_size(g_mlx_ptr, &x, &y); */
	/* printf("x = %d\n", x); */
	/* printf("y = %d\n", y); */
	createImage();
	playerMovement(&g_player);
	drawMap(g_info->map);
	drawPlayer(&g_player);
	cast_All_Rays(&g_player, &ray);
	/* cast_All_Rays(&g_player, &g_ray); */
	/* mlx_clear_window(g_mlx_ptr, g_win_mlx); */
	mlx_put_image_to_window(g_mlx_ptr, g_win_mlx, g_img_ptr, 0, 0);
	///mlx_destroy_image(g_mlx_ptr, g_img_ptr);
	g_img_ptr = 0;
	(void)info;
	return (0);
}

static void		init_mlx()
{
	g_mlx_ptr = 0;
	if (!(g_mlx_ptr = mlx_init()))
	{
		ft_putstr_fd("Error\nfaile init mlx\n", STDOUT);
		exit(freeAll(ERROR));
	}
}

static void		createWindow(void)
{
	g_win_mlx = 0;
	if (!(g_win_mlx = mlx_new_window(g_mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "3D")))
	{
		ft_putstr_fd("Error\nfaile open window\n", STDOUT);
		exit(freeAll(ERROR));
	}
}

int				main(int ac, char **av)
{
	t_info		info;
	int			keyCode;

	info.map = 0;
	g_texture[0].texture_ptr = 0;
	g_info = &info;
	if (ac != 2)
	{
		write(1, "Error\nnumber argument\n", 24);
		return (ERROR);
	}
	if (get_file_descriptor(&info, av[1]) == ERROR)
		return (ERROR);
	if (parsing_map(&info) == ERROR)
		return (ERROR);
	init_mlx();
	getTexture(g_texture);
	createWindow();
	g_map = (char **)info.map;
	initPlayer();
	mlx_hook(g_win_mlx, 2, (1L << 0), &keyPressed, &keyCode);
	mlx_hook(g_win_mlx, 3, (1L << 1), &keyRelease, &keyCode);
	mlx_loop_hook(g_mlx_ptr, &gameLoop, &info);
	mlx_loop(g_mlx_ptr);
	return (0);
}
