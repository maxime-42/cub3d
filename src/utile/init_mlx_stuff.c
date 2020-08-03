#include "cub3d.h"

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

static	void	createWindow(void *mlx_ptr, void *win_mlx, char *filename)
{
  	int	width;
	int	height;

	mlx_get_screen_size(g_mlx_ptr, &width, &height);
	if (g_screen_width > width)
		g_screen_width = width;
	if (g_screen_height > height)
		g_screen_height = height;
	g_win_mlx = 0;
	if (!filename)
	{
		if (!(win_mlx = mlx_new_window(mlx_ptr, g_screen_width, g_screen_height, "3D")))
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
