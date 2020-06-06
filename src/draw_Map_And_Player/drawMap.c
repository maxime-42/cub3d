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
