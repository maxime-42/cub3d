#include "cub3d.h"

void	getTexture(t_texture texture[NUM_TEXTURE])
{
	int	bpp;
	int	size_line;
	int	endian;
	int	i;

	i = -1;
	while (++i < NUM_TEXTURE)
	{
		texture[i].texture_ptr = mlx_xpm_file_to_image(g_mlx_ptr,
		texture[i].path, &texture[i].width, &texture[i].height);
		texture[i].wallTexture = (int *)mlx_get_data_addr(
		texture[i].texture_ptr, &bpp, &size_line, &endian);
		if (!texture[i].texture_ptr)
		{
			ft_putstr_fd("Error\nFailer texture ptr\n", STDOUT);
			exit (freeAll(ERROR));
		}
	}
}
