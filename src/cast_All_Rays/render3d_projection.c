#include "cub3d.h"

void			render3d_projection(t_ray *ray, int columnId)
{
	float	rayDistance;
	float	distanceProjectionPlane;
	float	wallStripHeight;
	float	x;
	float	y;

	rayDistance = ray->distance;
	distanceProjectionPlane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
	wallStripHeight = (TILE_SIZE / rayDistance) * distanceProjectionPlane;
	x = columnId * WALL_STRIP_WIDTH;
	y = (WINDOW_HEIGHT / 2) - (wallStripHeight / 2);
	Rect(x, y, WALL_STRIP_WIDTH, wallStripHeight, 0xD3D0D0);
}
