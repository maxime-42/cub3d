#include "cub3d.h"

void	init_Struct_Ray(t_ray *ray)
{
	ray->isRayFacingUp = 0;
	/* ray->yintercept = 0; */
	/* ray->xintercept = 0; */
	ray->isRayFacingDown = 0;
	ray->isRayFacingRight = 0;
	ray->isRayFacingLeft = 0;
	ray->wasHitVertical = 0;
    ray->wallHitX = 0;
    ray->wallHitY = 0;
	ray->vertWallHitY = 0;
	ray->vertWallHitX = 0;
	ray->horzWallHitY = 0;
	ray->horzWallHitX = 0;
	ray->ystep = 0;
	ray->xstep = 0;
	ray->rayAngle = 0;
    ray->foundHorzWallHit = 0;
	ray->foundVertWallHit = 0;
}

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
	/* printf("NUM_RAYS = %d\n", NUM_RAYS); */
	while(columnId < NUM_RAYS)
	/* while(columnId < 16) */
	{
		g_ray.rayAngle = normalizeAngle(g_ray.rayAngle);
		ray_Facing(ray);
		rayHorizontal(ray);
		/* rayVertical(ray); */
		/* the_Smallest_Of_The_Distances(ray, player); */
		/* drawline(player->y * MINIMAP_SCALE_FACTOR, player->x * MINIMAP_SCALE_FACTOR, ray->distance * MINIMAP_SCALE_FACTOR, 0xff0000, ray->rayAngle); */
		ray->rayAngle += (FOV_ANGLE / NUM_RAYS);
		columnId++;
	}
	(void)player;
	(void)ray;
}
