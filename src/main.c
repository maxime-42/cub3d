#include "cub3d.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static int		gameLoop(t_info *info)
{
	createImage();
	playerMovement(&g_player);
	drawMap(g_info->map);
	cast_All_Rays(&g_player, &g_ray);
	drawPlayer(&g_player);
	/* mlx_clear_window(g_mlx_ptr, g_win_mlx); */
	mlx_put_image_to_window(g_mlx_ptr, g_win_mlx, g_img_ptr, 0, 0);
	///mlx_destroy_image(g_mlx_ptr, g_img_ptr);
	g_img_ptr = 0;
	(void)info;
	return (0);
}

int				main(int ac, char **av)
{
	t_info		info;

	info.keyCode = 0;
	info.map = 0;
	g_info = &info;
	g_mlx_ptr = 0;
	g_win_mlx = 0;
	g_img_ptr = 0;
	if (ac != 2)
	{
		write(1, "Error\nnumber argument\n", 24);
		return (ERROR);
	}
	if (get_file_descriptor(&info, av[1]) == ERROR)
		return (ERROR);
	if (parsing_map(&info) == ERROR)
		return (ERROR);
	close(info.fd);
	g_map = (char **)info.map;
	createWindow();
	initPlayer(info);
	mlx_hook(g_win_mlx, 2, (1L << 0), &keyPressed, &g_info->keyCode);
	mlx_hook(g_win_mlx, 3, (1L << 1), &keyRelease, &g_info->keyCode);
	mlx_loop_hook(g_mlx_ptr, &gameLoop, &info);
	mlx_loop(g_mlx_ptr);
	return (0);
}
