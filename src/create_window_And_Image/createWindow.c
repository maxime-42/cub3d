#include "cub3d.h"

void	createWindow(void)
{
	if (!(g_mlx_ptr = mlx_init()))
	{
		ft_putstr_fd("Error\nfaile init mlx\n", STDOUT);
		exit(freeAll(ERROR));
	}
	if (!(g_win_mlx = mlx_new_window(g_mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "3D")))
	{
		ft_putstr_fd("Error\nfaile open window\n", STDOUT);
		exit(freeAll(ERROR));
	}
}
