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

float		normalizeAngle(float angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
	{
		angle = (2 * M_PI) + angle;
	}
	return (angle);
}

void		cast_All_Rays(t_player *player, t_ray *ray)
{
	int		columnId;

	columnId = 0;

	init_Struct_Ray(ray);
	ray->rayAngle = g_player.rotationAngle - (FOV_ANGLE / 2);
	/* while(columnId < NUM_RAYS) */
	while(columnId < 1)
	{
		g_ray.rayAngle = normalizeAngle(g_ray.rayAngle);
		ray_Facing(ray);
		rayHorizontal();
		/* drawline(player->y, player->x, TILE_SIZE * 2, color, ray->rayAngle); */
		ray->rayAngle += FOV_ANGLE / NUM_RAYS;
		columnId++;
	}
	(void)player;
	(void)ray;
}
