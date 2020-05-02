#include "cub3d.h"

void	renderMap(t_info *info, char **map)
{
	int	y;
	int	x;
	int	color;
	int	py;
	int	px;

	y = -1;
	while (map[++y])
	{
		x = -1;
		py = TILE_SIZE * y;
		if (py > 0)
			py -= y;
		while (map[y][++x])
		{
			if (map[y][x] == '0')
				color = 16775936;
			else
				color = 16711680;
  			px = TILE_SIZE * x;
			if (px > 0)
				px -= x;
			my_pixel_put(info, x + px, y + py, color);
		}
	}
}
