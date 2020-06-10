#include "cub3d.h"

/*drawMap
je dessine la map avec des petits carré de la taille de TILE_SIZE
chaque caractere de la map est representer pas un carré de la taille de TILE_SIZE
*/

static	void	utilis(int *ly, int *lx, int j)
{
	int			y;
	int			x;

	y = -1;
	while (++y < TILE_SIZE)
	{
		x = -1;
		while (++x < TILE_SIZE)
		{
			g_image_data[*ly * WINDOW_WIDTH + *lx] = 0xFFFFFF;
			*lx += 1;
		}
		*ly += 1;
		*lx = j * TILE_SIZE;
	}
}

void	drawMap(char **map)
{
	int y;
	int x;
	int	lx;
	int	ly;

	y = -1;
	while (++y < MAP_NUM_ROWS)
	{
		x= -1;
		while (++x < MAP_NUM_COLS)
		{
			if (map[y][x] == '0' || ft_strchr("NSEW", map[y][x]))
			{
				lx = x * TILE_SIZE ;
				ly = y * TILE_SIZE ;
				utilis(&ly, &lx, x);
			}
		}
	}
}
