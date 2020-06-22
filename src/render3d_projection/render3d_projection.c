#include "cub3d.h"

void	render3d_projection(t_ray *ray, int columnId)
{
		float	rayDistance;
		float	distanceProjectionPlane;
		float	wallStripHeight;

		rayDistance = ray->distance;
		distanceProjectionPlane = (WINDOW_WIDTH / 2) / Math.tan(FOV_ANGLE / 2);
		wallStripHeight = (TILE_SIZE / rayDistance) * distanceProjectionPlane;
		Rect(columnId * WALL_STRIP_WIDTH, , (WINDOW_HEIGHT / 2) - (wallStripHeight / 2), WALL_STRIP_WIDTH, wallStripHeight, OxFFFFFF);
}
