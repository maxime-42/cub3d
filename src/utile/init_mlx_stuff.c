#include "cub3d.h"

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

void	*createWindow(void *mlx_ptr, char *filename)
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
	if (!filename)
	{
		if (!(win_mlx = mlx_new_window(mlx_ptr, g_screen_width, g_screen_height, "3D")))
		{
			ft_putstr_fd("Error\nfaile open window\n", STDOUT);
			exit(freeAll(ERROR));
		}
	}
	/* g_win_mlx = win_mlx; */
	return (win_mlx);
}

/* void		init_mlx_and_window(void *mlx_ptr, void *win_mlx, char *filename) */
/* { */
/* 	mlx_ptr = init_mlx(mlx_ptr); */
/* 	createWindow(g_mlx_ptr ,win_mlx, filename); */
/* 	(void)win_mlx; */
/* 	(void)filename; */
/* 	/\* exit(freeAll(ERROR)); *\/ */
/* } */
