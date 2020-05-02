#include "cub3d.h"

void	my_pixel_put(t_info *info, int j, int i, int rgb)
{
	int	pixel_y;
	int	pixel_x;
	int	tmp_j;

	pixel_y = -1;
	pixel_x = 0;
	tmp_j = j;
	while (++pixel_y < TILE_SIZE)
	{
		pixel_x = -1;
		j = tmp_j;
		while (++pixel_x < TILE_SIZE)
		{
			mlx_pixel_put(info->mlx_ptr, info->win_mlx, j, i, rgb);
			j++;
		}
		i++;
	}
	(void)rgb;
}
