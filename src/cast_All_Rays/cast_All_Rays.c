#include "cub3d.h"

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
	ray->foundVertWallHit = 0;
	ray->foundHorzWallHit = 0;
	ray->isRayFacingDown = 0;
	ray->isRayFacingUp = 0;
	ray->isRayFacingRight = 0;
	ray->isRayFacingLeft = 0;
	ray->distance = 0;
}

static void		ray_Facing(t_ray *ray)
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

static float	normalizeAngle(float angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
	{
		angle = (2 * M_PI) + angle;
	}
	return (angle);
}

static void		the_Smallest_Of_The_Distances(t_ray *ray, t_player *player)
{
	float		horzHitDistance;
	float		vertHitDistance;

	horzHitDistance = 0;
	vertHitDistance = 0;
	if (ray->foundHorzWallHit == 1)
		horzHitDistance = distanceBetweenPoints(player->x, player->y,
								ray->horzWallHitX, ray->horzWallHitY);

	else
		horzHitDistance = MAX_VALUE;

	if (ray->foundVertWallHit == 1)
		vertHitDistance = distanceBetweenPoints(player->x, player->y,
								ray->vertWallHitX, ray->vertWallHitY);
	else
		vertHitDistance = MAX_VALUE;
	if (horzHitDistance < vertHitDistance)
	{

		ray->wallHitX = ray->horzWallHitX;
		ray->wallHitY = ray->horzWallHitY;
		ray->distance = horzHitDistance;
	}
	else
	{
		ray->wallHitX = ray->vertWallHitX;
		ray->wallHitY = ray->vertWallHitY;
		ray->distance = vertHitDistance;
	}
	if (vertHitDistance < horzHitDistance)
		ray->wasHitVertical = 1;
}

void			cast_All_Rays(t_player *player, t_ray *ray)
{
	int			columnId;

	columnId = 0;
	ray->rayAngle = g_player.rotationAngle - (FOV_ANGLE / 2);
	while (columnId < NUM_RAYS)
	{
		ray->rayAngle = normalizeAngle(ray->rayAngle);
		init_Struct_Ray(ray);
		ray_Facing(ray);
		rayHorizontal(ray, player);
		rayVertical(ray, player);
		the_Smallest_Of_The_Distances(ray, player);
		drawline(player->y * MINIMAP_SCALE_FACTOR, player->x * MINIMAP_SCALE_FACTOR, ray->distance * MINIMAP_SCALE_FACTOR, 0xff0000, ray->rayAngle);
		render3d_projection(ray, columnId);
		ray->rayAngle += (FOV_ANGLE / NUM_RAYS);
		columnId++;
	}
	(void)player;
	(void)ray;
}
