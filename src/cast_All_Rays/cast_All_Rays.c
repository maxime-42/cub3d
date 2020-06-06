#include "cub3d.h"

/* void			castAllRays() */
/* { */
/* 	int			columnId; */

/* 	columnId = 0; */
/* 	g_info->ray.rayAngle = g_info->player.rotationAngle - (FOV_ANGLE / 2); */
/* 	/\* while(columnId < NUM_RAYS) *\/ */
/* 	while (columnId < 1) */
/* 	{ */
/* 		cast_RayHorizontal(); */
/* 		/\* renderRays(&g_info->player, g_info->ray.rayAngle, 30); *\/ */
/* 		g_info->ray.rayAngle += FOV_ANGLE / NUM_RAYS; */
/* 		columnId++; */
/* 	} */
/* 	/\* mlx_put_image_to_window(g_mlx_ptr, g_win_mlx, g_img_ptr, 0, 0); *\/ */
/* } */

double		normalizeAngle(double angle)
{
	angle = remainder(angle, (2 * M_PI));
	/* angle = fmod(angle, (2 * M_PI)); */
	if (angle < 0)
	{
		angle = (2 * M_PI) + angle;
	}
	return (angle);
}

void		cast_All_Rays()
{
	int		columnId;

	columnId = 0;
	g_ray.rayAngle = g_player.rotationAngle - (FOV_ANGLE / 2);
	/* while(columnId < NUM_RAYS) */
	while (columnId < 1)
	{
		g_ray.rayAngle = normalizeAngle(g_ray.rayAngle);
		ray_Facing();
		rayHorizontal();
		/* draw_Ray(g_ray.rayAngle, 30, 0xF10B0B); */
		g_ray.rayAngle += FOV_ANGLE / NUM_RAYS;
		columnId++;
	}
}
