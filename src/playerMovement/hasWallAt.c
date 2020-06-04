#include "cub3d.h"

int			hasWallAt(int y, int x)
{
	int		mapGridIndexX;
	int		mapGridIndexY;

	if (x < 0 || x > g_window_width || y < 0 || y > g_window_height)
	{
		return (1);
	}
	mapGridIndexX = floor(x / TILE_SIZE);
	mapGridIndexY = floor(y / TILE_SIZE);
	return (g_map[mapGridIndexY][mapGridIndexX] != '0');
}
