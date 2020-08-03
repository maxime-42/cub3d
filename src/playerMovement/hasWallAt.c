#include "cub3d.h"

/* int			hasWallAt(float y, float x) */
/* { */
/* 	int		mapGridIndexX; */
/* 	int		mapGridIndexY; */

/* 	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT) */
/* 	{ */
/* 		return (1); */
/* 	} */
/* 	mapGridIndexX = floor(x / g_tile_size); */
/* 	mapGridIndexY = floor(y / g_tile_size); */
/* 	return (g_map[mapGridIndexY][mapGridIndexX] != '0'); */
/* } */

int			hasWallAt(float y, float x)
{
	int		mapGridIndexX;
	int		mapGridIndexY;

	if (x < 0 || x > (g_map_num_cols * g_tile_size )|| y < 0 || y > (g_map_num_rows * g_tile_size))
	{
		return (1);
	}
	mapGridIndexX = floor(x / g_tile_size);
	mapGridIndexY = floor(y / g_tile_size);
	/* if (ft_strchr("NSEW", g_map[mapGridIndexY][mapGridIndexX])) */
	/* 	return (0); */
	return (g_map[mapGridIndexY][mapGridIndexX] == '1');
}
