#include "cub3d.h"

/* void	test(int corX, int corY, int width, int height, int color) */
/* { */
/* 	int i; */
/* 	int j; */

/* 	i = 0; */
/* 	j = 0; */
/* 	while (i < height) */
/* 	{ */
/* 		while (j < width) */
/* 		{ */
/* 			g_image_data[(i + corY - width) * WINDOW_WIDTH + (j + corX - height)] = color; */
/* 			j++; */
/* 		} */
/* 		j = 0; */
/* 		i++; */
/* 	} */
/* } */

void test(int corX, int corY, int width, int height, int color)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < height)
	{
		while (j < width)
		{
			g_image_data[(i + corY) * WINDOW_WIDTH + (j + corX)] = color;
			j++;
		}
		j = 0;
		i++;
	}
}


void			render3d_projection(t_ray *ray, int columnId)
{
	float	rayDistance;
	float	distanceProjectionPlane;
	float		wallStripHeight;
	int		x;
	int		y;

	rayDistance = ray->distance;
	distanceProjectionPlane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
	wallStripHeight = (TILE_SIZE / rayDistance) * distanceProjectionPlane;
	x = columnId * WALL_STRIP_WIDTH;
	y = (WINDOW_HEIGHT / 2) - (wallStripHeight / 2);
	test(x, y, WALL_STRIP_WIDTH, wallStripHeight, 0xD3D0D0);

	/* Rect(x, y, WALL_STRIP_WIDTH, wallStripHeight, 0xD3D0D0); */
}
