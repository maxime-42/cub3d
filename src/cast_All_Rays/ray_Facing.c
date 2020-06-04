#include "cub3d.h"

void		ray_Facing()
{
	if (g_ray.rayAngle > 0 && g_ray.rayAngle < M_PI)
		g_ray.isRayFacingDown = 1;
	else
		g_ray.isRayFacingUp = 1;
	if (g_ray.rayAngle < (0.5 * M_PI) || g_ray.rayAngle > (1.5 * M_PI))
		g_ray.isRayFacingRight = 1;
	else
		g_ray.isRayFacingLeft = 1;
}
