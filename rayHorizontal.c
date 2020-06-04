#include "cub3d.h"

static void	findWall(int nextHorzTouchY, int nextHorzTouchX);

void		cast_RayHorizontal()
{
	t_ray	*ray;
	int		nextHorzTouchY;
	int	nextHorzTouchX;

	ray = &g_info->ray;
	rayFacing(ray);
	// Find the y-coordinate of the closest horizontal grid intersenction
	ray->yintercept = floor(g_info->player.y / TILE_SIZE) * TILE_SIZE;
	ray->yintercept += (ray->isRayFacingDown) ? TILE_SIZE : 0;
	// Find the x-coordinate of the closest horizontal grid intersection
	ray->xintercept = g_info->player.x + ((ray->yintercept - g_info->player.y) / tan(ray->rayAngle));
	// Calculate the increment xstep and ystep
	ray->ystep = TILE_SIZE;
	ray->ystep *= ray->isRayFacingUp ? -1 : 1;

	ray->xstep = TILE_SIZE / tan(ray->rayAngle);
	ray->xstep *= (ray->isRayFacingLeft && ray->xstep > 0) ? -1 : 1;
	ray->xstep *= (ray->isRayFacingRight && ray->xstep < 0) ? -1 : 1;
	nextHorzTouchX = ray->xintercept;
	nextHorzTouchY = ray->yintercept;
	if (ray->isRayFacingUp)
		nextHorzTouchY--;
	findWall(nextHorzTouchY, nextHorzTouchX);
}

static void	findWall(int nextHorzTouchY, int nextHorzTouchX)
{
	float	lenght;
	char	**map;

	map = g_info->map;
	while (nextHorzTouchX >= 0 && nextHorzTouchX <= g_window_width &&  nextHorzTouchY >= 0 && nextHorzTouchY <= g_window_height)
	{
		if (hasWallAt(nextHorzTouchY, nextHorzTouchX))
		{
			g_info->ray.wallHitX = nextHorzTouchX;
			g_info->ray.wallHitY = nextHorzTouchY;
			lenght = distanceBetweenPoints(g_info->player.x, g_info->player.y, g_info->ray.wallHitX, g_info->ray.wallHitY);
			drawRay(&g_info->player, g_info->ray.rayAngle, lenght);
			return ;
		}
		nextHorzTouchX += g_info->ray.xstep;
		nextHorzTouchY += g_info->ray.ystep;
    }
	(void)map;
}
