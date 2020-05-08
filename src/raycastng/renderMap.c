#include "cub3d.h"

void	my_pixel_put(t_pixel *pixel)
{
	int	y;
	int	x;
	int	tmp_x;

	y = -1;
	tmp_x = pixel->x;
	while (++y < pixel->size)
	{
		x = -1;
		pixel->x = tmp_x;
		while (++x < pixel->size)
		{
			mlx_pixel_put(pixel->mlx_ptr, pixel->win_mlx,
			pixel->x, pixel->y, pixel->color);
			pixel->x++;
		}
		pixel->y++;
	}
}

void	renderMap(char **map, t_pixel *pixel)
{
	int	y;
	int	x;
	int	py;
	int	px;

	y = -1;
	while (map[++y])
	{
		x = -1;
		py = pixel->size * y;
		if (py > 0)
			py -= y;
		while (map[y][++x])
		{
			pixel->color = (map[y][x] == '0') ? 16775936 : 16711680;
			px = TILE_SIZE * x;
			if (px > 0)
				px -= x;
			pixel->x = x + px;
			pixel->y = y + py;
			my_pixel_put(pixel);
		}
	}
}
