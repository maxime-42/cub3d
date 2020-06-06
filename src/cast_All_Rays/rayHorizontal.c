#include "cub3d.h"

static void	findWall(int nextHorzTouchY, int nextHorzTouchX)
{
	float	lenght;
	char	**map;

	map = g_info->map;
	lenght = 0;
	while (nextHorzTouchX >= 0 && nextHorzTouchX <= WINDOW_WIDTH && nextHorzTouchY >= 0 && nextHorzTouchY <= WINDOW_HEIGHT)
	{
		if (hasWallAt(nextHorzTouchY, nextHorzTouchX))
		{
			g_ray.wallHitX = nextHorzTouchX;
			g_ray.wallHitY = nextHorzTouchY;
			lenght = distanceBetweenPoints(g_player.x, g_player.y, g_ray.wallHitX, g_ray.wallHitY);
			draw_Ray(g_ray.rayAngle, lenght, 0xF10B0B);
			break;
		}
		nextHorzTouchX += g_ray.xstep;
		nextHorzTouchY += g_ray.ystep;
    }
	(void)map;
}

void		rayHorizontal()
{
	int		nextHorzTouchY;
	int		nextHorzTouchX;

	// Find the y-coordinate of the closest horizontal grid intersenction
	g_ray.yintercept = floor(g_player.y / TILE_SIZE) * TILE_SIZE;
	g_ray.yintercept += (g_ray.isRayFacingDown) ? TILE_SIZE : 0;
	// Find the x-coordinate of the closest horizontal grid intersection
	g_ray.xintercept = g_player.x + ((g_ray.yintercept - g_player.y) / tan(g_ray.rayAngle));
	// Calculate the increment xstep and ystep
	g_ray.ystep = TILE_SIZE;
	g_ray.ystep *= g_ray.isRayFacingUp ? -1 : 1;

	g_ray.xstep = TILE_SIZE / tan(g_ray.rayAngle);
	g_ray.xstep *= (g_ray.isRayFacingLeft && g_ray.xstep > 0) ? -1 : 1;
	g_ray.xstep *= (g_ray.isRayFacingRight && g_ray.xstep < 0) ? -1 : 1;
	nextHorzTouchX = g_ray.xintercept;
	nextHorzTouchY = g_ray.yintercept;
	if (g_ray.isRayFacingUp)
		nextHorzTouchY--;
	findWall(nextHorzTouchY, nextHorzTouchX);
}
