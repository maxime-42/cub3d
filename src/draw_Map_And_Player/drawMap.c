#include "cub3d.h"

/*drawMap
je dessine la map avec des petits carré de la taille de TILE_SIZE
chaque caractere de la map est representer pas un carré de la taille de TILE_SIZE
*/

void	drawMap(char **map)
{
	int	y;
	int	x;
	int	column;

	y = -1;
	while (map[++y])
	{
		x = -1;
		column = 0;
		column += (WINDOW_WIDTH * TILE_SIZE * y);
		while (map[y][++x])
		{
			if (map[y][x] == '0' || ft_strchr("NSEW", map[y][x]))
				drawRect(column, TILE_SIZE, COLOR_FREE_SPACE);
			column += TILE_SIZE;
		}
	}
}

void	ft_renderMap()
{

	int i;
	int j;
	int k;
	int l;
	int	lx;
	int	ly;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	while (i < MAP_NUM_ROWS)
	{
		j = 0;
		while (j < MAP_NUM_COLS)
		{
			if (g_map[i][j] == '1')
			{
				lx = j * TILE_SIZE ;
				ly = i * TILE_SIZE ;
				l = 0;
				while (l < TILE_SIZE )
				{
					while(k < TILE_SIZE )
					{
						g_image_data[ly * WINDOW_WIDTH + lx] = 0xFFFFFF;
						lx++;
						k++;
					}
					lx = j * TILE_SIZE ;
					ly++;
					k = 0;
					l++;
				}
			}
			j++;
		}

		i++;
	}
}
