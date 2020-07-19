#include "cub3d.h"

void		render3d_projection(t_ray *ray, int columnId)
{
	t_wall	wall;

	wall.correctWallDistance = ray->distance * cos(ray->rayAngle - g_player.rotationAngle);
	wall.distanceProjectionPlane = (g_window_width / 2) / tan(FOV_ANGLE / 2);
	wall.wallStripHeight = (g_tile_size / wall.correctWallDistance) * wall.distanceProjectionPlane;
	wall.wallTop = (g_window_height / 2) - (wall.wallStripHeight / 2);
	if (wall.wallTop < 0)
		wall.wallTop = 0;
	wall.wallBottom = (g_window_height / 2) + (wall.wallStripHeight / 2);
	if (wall.wallBottom > g_window_height)
		wall.wallBottom = g_window_height;
	draw_Wall(ray, &wall, columnId);
}
