#include "cub3d.h"

void		ray_Facing(t_ray *ray)
{
	if (ray->rayAngle > 0 && ray->rayAngle < M_PI)
		ray->isRayFacingDown = 1;
	else
		ray->isRayFacingUp = 1;
	if (ray->rayAngle < (0.5 * M_PI) || ray->rayAngle > (1.5 * M_PI))
		ray->isRayFacingRight = 1;
	else
		ray->isRayFacingLeft = 1;
}

double	normalizeAngle(double angle)
{
	angle = remainder(angle, (2 * M_PI));
	/* angle = fmod(angle, (2 * M_PI)); */
	if (angle < 0)
	{
		angle = (2 * M_PI) + angle;
	}
	return (angle);
}

void			cast_All_Rays(t_player *player, t_ray *ray)
{
	int			columnId;
	int			color;

	color =  0xff0000;
	columnId = 0;
	ray->rayAngle = g_player.rotationAngle - (FOV_ANGLE / 2);
	/* printf("NUM_RAYS = %d\n", NUM_RAYS); */
	/* printf("MAP_NUM_COLS = %d\n", MAP_NUM_COLS); */
	while(columnId < NUM_RAYS)
	/* while(1 < NUM_RAYS) */
	{
		g_ray.rayAngle = normalizeAngle(g_ray.rayAngle);
		/* ray_Facing(); */
		/* rayHorizontal(); */
		drawline(player->y, player->x, TILE_SIZE * 2, color, ray->rayAngle);
		ray->rayAngle += FOV_ANGLE / NUM_RAYS;
		columnId++;
	}
	(void)player;
	(void)ray;
	(void)color;
}
