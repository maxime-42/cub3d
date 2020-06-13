#include "cub3d.h"

void	init_Struct_Ray(t_ray *ray)
{
	ray->isRayFacingUp = 0;
	ray->isRayFacingDown = 0;
	ray->isRayFacingRight = 0;
	ray->isRayFacingLeft = 0;
	ray->rayAngle = 0;
    ray->wallHitX = 0;
    ray->wallHitY = 0;
    ray->foundHorzWallHit = 0;
}
