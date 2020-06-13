#include "cub3d.h"

static void	next_Horz_Intercept(float nextHorzTouchY, float nextHorzTouchX, float ystep, float xstep)
{
	float	lenght;

	while (nextHorzTouchX >= 0 && nextHorzTouchX <= WINDOW_WIDTH &&
	nextHorzTouchY >= 0 && nextHorzTouchY <= WINDOW_HEIGHT)
	{
		if (hasWallAt(nextHorzTouchY, nextHorzTouchX))
		{
			g_ray.wallHitX = nextHorzTouchX;
			g_ray.wallHitY = nextHorzTouchY;
		    g_ray.foundHorzWallHit = 1;
			/* printf("nextHorzTouchY = %f\n", nextHorzTouchY); */
			/* printf("nextHorzTouchX = %f\n", nextHorzTouchX); */
			lenght = distanceBetweenPoints(g_player.x, g_player.y, g_ray.wallHitX, g_ray.wallHitY);
			/* printf("lenght = %f\n", lenght); */
			drawline(g_player.y, g_player.x, lenght, 0xff0000, g_ray.rayAngle);
			/* draw_Ray(g_ray.rayAngle, lenght, 0xff0000); */
			return ;
		}
		nextHorzTouchX += xstep;
		nextHorzTouchY += ystep;
    }
}

void		rayHorizontal(t_ray *ray)
{
	float	nextHorzTouchY;
	float	nextHorzTouchX;
	float	ystep;
	float	xstep;

	// Find the y-coordinate of the closest horizontal grid intersenction
	ray->yintercept = floor(g_player.y / TILE_SIZE) * TILE_SIZE;
	if (ray->isRayFacingDown)
		ray->yintercept += TILE_SIZE;
	// Find the x-coordinate of the closest horizontal grid intersection
	ray->xintercept = g_player.x + ((ray->yintercept - g_player.y) / tan(ray->rayAngle));

	// Calculate the increment xstep and ystep
	ystep = TILE_SIZE;
	if (ray->isRayFacingUp)
		ystep *= -1;

	xstep = TILE_SIZE / tan(ray->rayAngle);
	if (ray->isRayFacingLeft && xstep > 0)
		xstep *= -1;
	if (ray->isRayFacingRight && xstep < 0)
		xstep *= -1;
	nextHorzTouchX = ray->xintercept;
	nextHorzTouchY = ray->yintercept;
	if (ray->isRayFacingUp)
		nextHorzTouchY--;
	next_Horz_Intercept(nextHorzTouchY, nextHorzTouchX, ystep, xstep);
}
