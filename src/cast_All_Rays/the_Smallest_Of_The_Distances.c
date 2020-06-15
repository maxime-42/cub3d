#include "cub3d.h"

void		the_Smallest_Of_The_Distances(t_ray *ray, t_player *player)
{
	float	horzHitDistance;
	float	vertHitDistance;

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
	/* ft_drawline(player->y, player>x, ray->distance, 0xff0000, rayAngle); */
}
