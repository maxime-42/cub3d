#include "cub3d.h"


void	get_PositionPlayer(char **map, int *y, int *x)
{
	int	line;
	int	column;
	int	start;

	line = -1;
	while (map[++line])
	{
		column = -1;
		start = 0;		
		if (line)
			start = start + (g_width * TILE_SIZE * line);
		while (map[line][++column])
		{
			if (ft_strchr("NSEW", map[line][column]))
			{
				*x = g_width / 2;
				*y = (g_width / 13);
				return ;
			}
			start += TILE_SIZE;
		}
	}
}

/* void	get_PositionPlayer(char **map, int *y, int *x) */
/* { */
/* 	int	line; */
/* 	int	column; */

/* 	line = -1; */
/* 	while (map[++line]) */
/* 	{ */
/* 		column = -1; */
/* 		while (map[line][++column]) */
/* 		{ */
/* 			if (ft_strchr("NSEW", map[line][column])) */
/* 			{ */
/* 				*x = 0; */
/* 				*y = start; */
/* 				return ; */
/* 			} */
/* 		} */
/* 	} */
/* } */
