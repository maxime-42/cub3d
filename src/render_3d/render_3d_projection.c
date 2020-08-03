#include "cub3d.h"

static int	choice_of_texture(t_ray *ray)
{
	if (ray->isRayFacingUp && !ray->wasHitVertical)
		return (0);
	if (ray->isRayFacingDown && !ray->wasHitVertical)
		return (1);
	if (ray->isRayFacingLeft && ray->wasHitVertical)
		return (2);
	if (ray->isRayFacingRight && ray->wasHitVertical)
		return (3);
	(void)ray;
	return (0);
}

static void	draw_Ceiling(t_wall *wall, int columnId)
{
	int	top;

	top = 0;
	while (top < wall->wallTop)
	{
		g_image_data[top * g_window_width + columnId] = 0xC3BDBD;
		top++;
	}
}


static void	draw_Floor(t_wall *wall, int columnId)
{
	int	bottom;

	bottom = (int)wall->wallBottom;
	while (bottom < g_window_height)
	{
		g_image_data[(bottom * g_window_width) + columnId] = 0xFEFEFE;
		bottom++;
	}
}

static void	draw_Wall(t_ray *ray, t_wall *wall, int columnId)
{
	int	textureOffsetX;
	int	textureOffsetY;
	int	textureColor;
	int	distanceFromTop;
	int	index;

	index = choice_of_texture(ray);
	if (ray->wasHitVertical == 1)
		textureOffsetX = (int)(ray->wallHitY * g_texture[index].width / g_tile_size) % g_texture[index].width;
	else
		textureOffsetX = (int)(ray->wallHitX * g_texture[index].width / g_tile_size) % g_texture[index].width;
	while (wall->wallTop < wall->wallBottom)
	{
		distanceFromTop = wall->wallTop + (wall->wallStripHeight / 2) - (g_window_height / 2);
		textureOffsetY = distanceFromTop * ((float)g_texture[index].height / wall->wallStripHeight);
		textureColor = g_texture[index].wallTexture[(g_texture[index].width * textureOffsetY) + textureOffsetX];
		g_image_data[(wall->wallTop * g_window_width) + columnId] = textureColor;
		wall->wallTop++;
	}
}


void		render3d_projection(t_ray *ray, int columnId, t_sprite *sprite)
{
	t_wall	wall;

	wall.correctWallDistance = ray->distance * cos(ray->rayAngle - g_player.rotationAngle);
	sprite->buffer[columnId] = wall.correctWallDistance;//test;
	wall.distanceProjectionPlane = (g_window_width / 2) / tan(g_fov_angle / 2);
	wall.wallStripHeight = (g_tile_size / wall.correctWallDistance) * wall.distanceProjectionPlane;
	wall.wallTop = (g_window_height / 2) - (wall.wallStripHeight / 2);
	if (wall.wallTop < 0)
		wall.wallTop = 0;
	wall.wallBottom = (g_window_height / 2) + (wall.wallStripHeight / 2);
	if (wall.wallBottom > g_window_height)
		wall.wallBottom = g_window_height;
	draw_Ceiling(&wall, columnId);
	draw_Wall(ray, &wall, columnId);
	draw_Floor(&wall, columnId);
}
