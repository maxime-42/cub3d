#include "cub3d.h"

void		render3d_projection(t_ray *ray, int columnId)
{
	t_wall	wall;

	wall.correctWallDistance = ray->distance * cos(ray->rayAngle - g_player.rotationAngle);
	wall.distanceProjectionPlane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
	wall.wallStripHeight = (TILE_SIZE / wall.correctWallDistance) * wall.distanceProjectionPlane;
	wall.wallTop = (WINDOW_HEIGHT / 2) - (wall.wallStripHeight / 2);
	if (wall.wallTop < 0)
		wall.wallTop = 0;
	wall.wallBottom = (WINDOW_HEIGHT / 2) + (wall.wallStripHeight / 2);
	if (wall.wallBottom > WINDOW_HEIGHT)
		wall.wallBottom = WINDOW_HEIGHT;
	draw_Wall(ray, &wall, columnId);
}
