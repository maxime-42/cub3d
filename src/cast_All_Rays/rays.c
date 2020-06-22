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

static	void	init_Struct_Ray(t_ray *ray)
{
	ray->xintercept = 0;
	ray->yintercept = 0;
	ray->xstep = 0;
	ray->ystep = 0;
	ray->wallHitX = 0;
	ray->wallHitY = 0;
	ray->wasHitVertical = 0;
	ray->vertWallHitX = 0;
	ray->vertWallHitY = 0;
	ray->horzWallHitY = 0;
	ray->horzWallHitX = 0;
	/* ray->rayAngle = 0; */
	ray->foundVertWallHit = 0;
	ray->foundHorzWallHit = 0;
	ray->isRayFacingDown = 0;
	ray->isRayFacingUp = 0;
	ray->isRayFacingRight = 0;
	ray->isRayFacingLeft = 0;
	ray->distance = 0;
}

void			cast_All_Rays(t_player *player, t_ray ray[NUM_RAYS])
{
	int			columnId;
	float		rayAngle;

	columnId = 0;
	rayAngle = player->rotationAngle - (FOV_ANGLE / 2);
	while(columnId < NUM_RAYS)
	{
		ray[columnId]rayAngle = normalizeAngle(ray->rayAngle);
		init_Struct_Ray(&ray);
		ray_Facing(ray);
		rayHorizontal(ray);
		rayVertical(ray);
		the_Smallest_Of_The_Distances(ray, player);
		drawline(player->y * MINIMAP_SCALE_FACTOR, player->x * MINIMAP_SCALE_FACTOR, ray->distance * MINIMAP_SCALE_FACTOR, 0xff0000, ray->rayAngle);
		render3d_projection(ray, columnId);
		ray->rayAngle += (FOV_ANGLE / NUM_RAYS);
		columnId++;
	}
	(void)player;
	(void)ray;
}

