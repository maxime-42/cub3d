#include "cub3d.h"

void	square(int start, int size, int color)
{
	int	y;
	int	x;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			g_image_data[start++] = color;
		}
		start = start - x;
		start = start + g_width;
	}
}

void	renderMap(char **map)
{
	int	y;
	int	x;
	int	color;
	int	start;

	y = -1;
	color = 0;
	while (map[++y])
	{
		x = -1;
		start = 0;
		start = start + (g_width * TILE_SIZE * y);
		while (map[y][++x])
		{
			if (map[y][x] == '0' || ft_strchr("NSEW", map[y][x]))
				color = 0xFFFFFF;
			else
				color = 0xFF0000;
			square(start, TILE_SIZE, color);
			start += TILE_SIZE;
		}
	}
}


/* void	renderMap(char **map) */
/* { */
/* 	int	y; */
/* 	int	x; */
/* 	int	color; */
/* 	int	start; */
/* 	int	size; */

/* 	y = -1; */
/* 	size = 30; */
/* 	color = 0; */
/* 	while (map[++y]) */
/* 	{ */
/* 		x = -1; */
/* 		start = 0; */
/* 		if (y) */
/* 			start = start + (g_width * size * y); */
/* 		while (map[y][++x]) */
/* 		{ */
/* 			if (map[y][x] == '0') */
/* 				color = 0xFFFFFF; */
/* 			else */
/* 				color = 0xFF0000; */
/* 			square(start, size, color); */
/* 			start += size; */
/* 		} */
/* 	} */
/* } */
