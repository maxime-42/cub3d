#include "cub3d.h"

static	void	*init_mlx(void *mlx_ptr)
{
	g_mlx_ptr = 0;
	if (!(mlx_ptr = mlx_init()))
	{
		ft_putstr_fd("Error\nfaile init mlx\n", STDOUT);
		exit(freeAll(ERROR));
	}
	g_mlx_ptr = mlx_ptr;
	return (mlx_ptr);
}

	void	createWindow(void *mlx_ptr, void *win_mlx, char *filename)
{
	g_win_mlx = 0;
	if (!filename)
	{
		if (!(win_mlx = mlx_new_window(mlx_ptr, g_window_width, g_window_height, "3D")))
		{
			ft_putstr_fd("Error\nfaile open window\n", STDOUT);
			exit(freeAll(ERROR));
		}

	}
	g_win_mlx = win_mlx;
}

void		init_mlx_and_window(void *mlx_ptr, void *win_mlx, char *filename)
{
	mlx_ptr = init_mlx(mlx_ptr);
	createWindow(g_mlx_ptr ,win_mlx, filename);
	(void)win_mlx;
	(void)filename;
	/* exit(freeAll(ERROR)); */
}
