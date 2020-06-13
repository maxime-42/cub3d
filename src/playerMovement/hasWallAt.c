#include "cub3d.h"

int			hasWallAt(float y, float x)
{
	int		mapGridIndexX;
	int		mapGridIndexY;

	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
	{
		return (1);
	}
	mapGridIndexX = floor(x / TILE_SIZE);
	mapGridIndexY = floor(y / TILE_SIZE);
	return (g_map[mapGridIndexY][mapGridIndexX] != '0');
}
