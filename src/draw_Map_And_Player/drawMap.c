#include "cub3d.h"

/*drawMap
je dessine la map avec des petits carré de la taille de TILE_SIZE
chaque caractere du carré est representer pas un carré de la taille de TILE_SIZE

*/
void	drawMap(char **map)
{
	int	y;
	int	x;
	int	color;
	int	line;

	y = -1;
	color = 0;
	while (map[++y])
	{
		x = -1;
		line = 0;
		line += (g_width * TILE_SIZE * y);
		while (map[y][++x])
		{
			if (map[y][x] == '0' || ft_strchr("NSEW", map[y][x]))
				color = COLOR_FREE_SPACE;
			else
				color = COLOR_WALL_SPACE;
			drawSquare(line, TILE_SIZE, color);
			line += TILE_SIZE;
		}
	}
}
