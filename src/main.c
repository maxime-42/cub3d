#include "cub3d.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int			main(int ac, char **av)
{
	t_info	info;
	int		keyCode = 0;

	info.map = 0;
	if (ac != 2)
		return (write(1, "Error\nnumber argument\n", 24));
	if (get_fd(&info, av[1]) == ERROR)
		return (ERROR);
	if (parse_map(&info) == ERROR)
		return (ERROR);
	g_info = &info;
	twoDMap_PlayerMovement(&info);
	mlx_put_image_to_window(g_mlx_ptr, g_win_mlx, g_img_ptr, 0, 0);
	mlx_hook(g_win_mlx, 2, (1L << 0), &keyPressed, &keyCode);
	mlx_hook(g_win_mlx, 3, (1L << 1), &keyRelease, &keyCode);
	mlx_loop(g_mlx_ptr);
	(void)keyCode;
	(void)g_info;
	return (0);
}
