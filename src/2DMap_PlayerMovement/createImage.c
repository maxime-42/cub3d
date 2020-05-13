#include "cub3d.h"

int	createImg()
{
	int	bpp;
	int	size_line;
	int	endian;

	if (!(g_img_ptr = mlx_new_image(g_mlx_ptr, g_width, g_height)))
	{
		ft_putstr_fd("Error\nfaile to get image pointer", STDOUT);
		return (freeAll(ERROR));
	}
	g_image_data = (int *)mlx_get_data_addr(g_img_ptr, &bpp, &size_line, &endian);
	if (!g_image_data)
	{
		ft_putstr_fd("Error\nfaile to get image data", STDOUT);
		return (freeAll(ERROR));
	}
	return (SUCCESS);
}
