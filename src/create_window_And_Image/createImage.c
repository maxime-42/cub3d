#include "cub3d.h"

void	createImage(void)
{
	int	bpp;
	int	size_line;
	int	endian;

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
