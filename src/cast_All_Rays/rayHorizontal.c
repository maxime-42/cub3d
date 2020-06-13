#include "cub3d.h"

static void	next_Horz_Intercept(float nextHorzTouchY, float nextHorzTouchX)
{
	float	lenght;

	while (nextHorzTouchX >= 0 && nextHorzTouchX <= WINDOW_WIDTH &&
	nextHorzTouchY >= 0 && nextHorzTouchY <= WINDOW_HEIGHT)
	{
		if (hasWallAt(nextHorzTouchY, nextHorzTouchX))
		{
			g_ray.wallHitX = nextHorzTouchX;
			g_ray.wallHitY = nextHorzTouchY;
			/* printf("nextHorzTouchY = %f\n", nextHorzTouchY); */
			/* printf("nextHorzTouchX = %f\n", nextHorzTouchX); */
			lenght = distanceBetweenPoints(g_player.x, g_player.y, g_ray.wallHitX, g_ray.wallHitY);
			/* printf("lenght = %f\n", lenght); */
			drawline(g_player.y, g_player.x, lenght, 0xff0000, g_ray.rayAngle);
			/* draw_Ray(g_ray.rayAngle, lenght, 0xff0000); */
			return ;
		}
		nextHorzTouchX += g_ray.xstep;
		nextHorzTouchY += g_ray.ystep;
    }
}

void		rayHorizontal()
{
	float	nextHorzTouchY;
	float	nextHorzTouchX;

	// Find the y-coordinate of the closest horizontal grid intersenction
	g_ray.yintercept = floor(g_player.y / TILE_SIZE) * TILE_SIZE;
	if (g_ray.isRayFacingDown)
		g_ray.yintercept += TILE_SIZE;
	// Find the x-coordinate of the closest horizontal grid intersection
	g_ray.xintercept = g_player.x + ((g_ray.yintercept - g_player.y) / tan(g_ray.rayAngle));

	// Calculate the increment xstep and ystep
	g_ray.ystep = TILE_SIZE;
	if (g_ray.isRayFacingUp)
		g_ray.ystep *= -1;

	g_ray.xstep = TILE_SIZE / tan(g_ray.rayAngle);
	if (g_ray.isRayFacingLeft && g_ray.xstep > 0)
		g_ray.xstep *= -1;
	if (g_ray.isRayFacingRight && g_ray.xstep < 0)
		g_ray.xstep *= -1;
	nextHorzTouchX = g_ray.xintercept;
	nextHorzTouchY = g_ray.yintercept;
	if (g_ray.isRayFacingUp)
		nextHorzTouchY--;
	next_Horz_Intercept(nextHorzTouchY, nextHorzTouchX);
}
