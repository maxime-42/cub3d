#include "cub3d.h"

static void	next_Horz_Intercept(t_ray *ray, float nextHorzTouchY, float nextHorzTouchX)
{
	float	tmp;

	while (nextHorzTouchX >= 0 && nextHorzTouchX <= WINDOW_WIDTH &&	nextHorzTouchY >= 0 && nextHorzTouchY <= WINDOW_HEIGHT)
	{
		tmp = 0;
		if (ray->isRayFacingUp)
			tmp = 1;
		if (hasWallAt(nextHorzTouchY - tmp, nextHorzTouchX))
		{
			ray->horzWallHitY = nextHorzTouchY;
			ray->horzWallHitX = nextHorzTouchX;
			ray->foundHorzWallHit = 1;
			return ;
		}
		nextHorzTouchX += ray->xstep;
		nextHorzTouchY += ray->ystep;
    }
}

void		rayHorizontal(t_ray *ray, t_player *player)
{
	float	nextHorzTouchY;
	float	nextHorzTouchX;

	// Find the y-coordinate of the closest horizontal grid intersenction
	ray->yintercept = floor(player->y / TILE_SIZE) * TILE_SIZE;
	if (ray->isRayFacingDown)
		ray->yintercept += TILE_SIZE;
	// Find the x-coordinate of the closest horizontal grid intersection
	ray->xintercept = player->x + ((ray->yintercept - player->y) / tan(ray->rayAngle));

	// Calculate the increment xstep and ystep
	ray->ystep = TILE_SIZE;
	if (ray->isRayFacingUp)
		ray->ystep *= -1;

	ray->xstep = TILE_SIZE / tan(ray->rayAngle);
	if (ray->isRayFacingLeft && ray->xstep > 0)
		ray->xstep *= -1;
	if (ray->isRayFacingRight && ray->xstep < 0)
		ray->xstep *= -1;
	nextHorzTouchX = ray->xintercept;
	nextHorzTouchY = ray->yintercept;
	/* if (ray->isRayFacingUp) */
	/* 	nextHorzTouchY--; */
	next_Horz_Intercept(ray, nextHorzTouchY, nextHorzTouchX);
}
