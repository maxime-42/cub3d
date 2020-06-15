#include "cub3d.h"
static void	next_Horz_Intercept(float nextVertTouchY, float nextVertTouchX,
								float ystep, float xstep)
{
	while (nextVertTouchX >= 0 && nextVertTouchX <= WINDOW_WIDTH
	&& nextVertTouchY >= 0 && nextVertTouchY <= WINDOW_HEIGHT)
	{
		if (hasWallAt(nextVertTouchX, nextVertTouchY))
		{
			g_ray.foundVertWallHit = 1;
			g_ray.vertWallHitX = nextVertTouchX;
			g_ray.vertWallHitY = nextVertTouchY;
			return ;
		}
		nextVertTouchX += xstep;
		nextVertTouchY += ystep;
	}
}

void		rayVertical(t_ray *ray)
{
	float	nextVertTouchX;
	float	nextVertTouchY;
	float	xstep;
	float	ystep;

	// Find the x coordinate of the closest vertical grid intersection
	ray->xintercept = floor(g_player.x / TILE_SIZE) * TILE_SIZE;
	if (ray->isRayFacingRight)
		ray->xintercept += TILE_SIZE;

	// Find the y coordinate of the closest vertical grid intersection
	ray->yintercept = g_player.y + (ray->xintercept - g_player.x) * tan(ray->rayAngle);

	//Calculate the increment for xstep and ystep
	xstep = TILE_SIZE;
	if (ray->isRayFacingLeft)
		xstep *= -1;

	ystep = TILE_SIZE * tan(ray->rayAngle);
	if (ray->isRayFacingUp && ystep > 0)
		ystep *= -1;
	if (ray->isRayFacingDown && ystep < 0)
		ystep *= -1;
	nextVertTouchX = xintercept;
	nextVertTouchY = yintercept;
	if (ray->isRayFacingLeft)////
		nextVertTouchX--;
	next_Horz_Intercept(nextVertTouchY, nextVertTouchX, ystep, xstep)
}
