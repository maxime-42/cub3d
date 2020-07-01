#include "cub3d.h"

/* void	drawRect(int corX, int corY, int width, int height, int color) */
/* { */
/* 	int i; */
/* 	int j; */

/* 	i = 0; */
/* 	j = 0; */
/* 	while (i < height) */
/* 	{ */
/* 		while (j < width) */
/* 		{ */
/* 			g_image_data[(i + corY) * WINDOW_WIDTH + (j + corX)] = color; */
/* 			j++; */
/* 		} */
/* 		j = 0; */
/* 		i++; */
/* 	} */
/* } */

void		draw_Wall(int wallTop, int wallBottom, int columnId, int wallStripHeight)
{
	int		top;
	int		textureOffsetX;
	int		textureOffsetY;
	int		texelColor;
	int		distanceFromTop;

	top = wallTop;
	if (g_ray.wasHitVertical == 1)
		textureOffsetX = (int)(g_ray.wallHitY * g_texture[0].width / TILE_SIZE) % g_texture[0].width;
	else
		textureOffsetX = (int)(g_ray.wallHitX * g_texture[0].width / TILE_SIZE) % g_texture[0].width;
	while (top < wallBottom)
	{
		distanceFromTop = top + (wallStripHeight / 2) - (WINDOW_HEIGHT / 2);
		textureOffsetY = distanceFromTop * ((float)g_texture[0].height / wallStripHeight);

		texelColor = g_texture[0].wallTexture[(g_texture[0].width * textureOffsetY) + textureOffsetX];
		/* g_image_data[(top * WINDOW_WIDTH) + columnId] = 0xD3D0D0; */
		g_image_data[(top * WINDOW_WIDTH) + columnId] = texelColor;
		top++;
	}
	(void)wallStripHeight;

}


void		render3d_projection(t_ray *ray, int columnId)
{
	float	correctWallDistance;
	float	distanceProjectionPlane;
	int		wallStripHeight;
	int		wallTop;
	int		wallBottom;

	correctWallDistance = ray->distance * cos(ray->rayAngle - g_player.rotationAngle);
	distanceProjectionPlane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
	wallStripHeight = (TILE_SIZE / correctWallDistance) * distanceProjectionPlane;

	wallTop = (WINDOW_HEIGHT / 2) - (wallStripHeight / 2);
	if (wallTop < 0)
		wallTop = 0;
	wallBottom = (WINDOW_HEIGHT / 2) + (wallStripHeight / 2);
	if (wallBottom > WINDOW_HEIGHT)
		wallBottom = WINDOW_HEIGHT;
	/* y = (WINDOW_HEIGHT / 2) - (wallStripHeight / 2); */
	/* if (y < 0 ||y >  WINDOW_HEIGHT) */
	/* 	y = 0; */
	/* if (x < 0 || x > WINDOW_WIDTH ) */
	/* 	x = 0; */
	draw_Wall(wallTop, wallBottom, columnId, wallStripHeight);
}
