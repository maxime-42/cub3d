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

void		drawCeiling(t_wall *wall, int columnId)
{
	int		top;

	top = 0;
	while (top < wall->wallTop)
	{
		g_image_data[(top * WINDOW_WIDTH) + columnId] = 0xA9C7FC;
		top++;
	}
}


void		drawFloor(t_wall *wall, int columnId)
{
	int		bottom;

	bottom = wall->wallBottom;
	while (bottom < WINDOW_HEIGHT)
	{
		g_image_data[(bottom * WINDOW_WIDTH) + columnId] = 0xFEFEFE;
		bottom++;
	}
}

void		draw_Wall(t_ray *ray, t_wall *wall, int columnId)
{
	int		textureOffsetX;
	int		textureOffsetY;
	int		textureColor;
	int		distanceFromTop;
	int		index;

	index = choice_of_texture(ray);
	if (ray->wasHitVertical == 1)
		textureOffsetX = (int)(ray->wallHitY * g_texture[index].width / TILE_SIZE) % g_texture[index].width;
	else
		textureOffsetX = (int)(ray->wallHitX * g_texture[index].width / TILE_SIZE) % g_texture[index].width;
	drawCeiling(wall, columnId);
	while (wall->wallTop < wall->wallBottom)
	{
		distanceFromTop = wall->wallTop + (wall->wallStripHeight / 2) - (WINDOW_HEIGHT / 2);
		textureOffsetY = distanceFromTop * ((float)g_texture[index].height / wall->wallStripHeight);
		textureColor = g_texture[index].wallTexture[(g_texture[index].width * textureOffsetY) + textureOffsetX];
		if (textureColor != 0x000000)
		g_image_data[(wall->wallTop * WINDOW_WIDTH) + columnId] = textureColor;
		wall->wallTop++;
	}
	drawFloor(wall, columnId);
}

void		getTexture(t_texture texture[NUM_TEXTURE])
{
	int		bpp;
	int		size_line;
	int		endian;
	int		i;

	i = -1;
	while (++i < NUM_TEXTURE)
	{
		texture[i].texture_ptr = mlx_xpm_file_to_image(g_mlx_ptr,
		texture[i].path, &texture[i].width, &texture[i].height);
		texture[i].wallTexture = (int *)mlx_get_data_addr(
		texture[i].texture_ptr, &bpp, &size_line, &endian);
		if (!texture[i].texture_ptr)
		{
			ft_putstr_fd("Error\nFailer texture ptr\n", STDOUT);
			exit (freeAll(ERROR));
		}
	}
}