#include "cub3d.h"

static void	next_Vert_Intercept(t_ray *ray, float nextVertTouchY, float nextVertTouchX)
{
	float	tmp;

	while (nextVertTouchX >= 0 && nextVertTouchX <= g_window_width
	&& nextVertTouchY >= 0 && nextVertTouchY <= g_window_height)
	{
		tmp = 0;
		if (ray->isRayFacingLeft)
			tmp = 1;
		if (hasWallAt(nextVertTouchY, nextVertTouchX - tmp))
		{
			ray->foundVertWallHit = 1;
			ray->vertWallHitX = nextVertTouchX;
			ray->vertWallHitY = nextVertTouchY;
			return ;
		}
		nextVertTouchX += ray->xstep;
		nextVertTouchY += ray->ystep;
	}
}

void		rayVertical(t_ray *ray, t_player *player)
{
	float	nextVertTouchX;
	float	nextVertTouchY;


	// Find the x coordinate of the closest vertical grid intersection
	ray->xintercept = floor(player->x / g_tile_size) * g_tile_size;
	if (ray->isRayFacingRight)
		ray->xintercept += g_tile_size;

	// Find the y coordinate of the closest vertical grid intersection
	ray->yintercept = player->y + (ray->xintercept - player->x) * tan(ray->rayAngle);

	//Calculate the increment for xstep and ystep
	ray->xstep = g_tile_size;
	if (ray->isRayFacingLeft)
		ray->xstep *= -1;

	ray->ystep = g_tile_size * tan(ray->rayAngle);
	if (ray->isRayFacingUp && ray->ystep > 0)
		ray->ystep *= -1;
	if (ray->isRayFacingDown && ray->ystep < 0)
		ray->ystep *= -1;
	nextVertTouchX = ray->xintercept;
	nextVertTouchY = ray->yintercept;
	/* if (ray->isRayFacingLeft) */
	/* 	nextVertTouchX--; */
	next_Vert_Intercept(ray, nextVertTouchY, nextVertTouchX);
}
