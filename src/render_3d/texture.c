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
		g_image_data[(top * g_window_width) + columnId] = 0xA9C7FC;
		top++;
	}
}


void		drawFloor(t_wall *wall, int columnId)
{
	int		bottom;

	bottom = (int)wall->wallBottom;
	while (bottom < g_window_height)
	{
		g_image_data[(bottom * g_window_width) + columnId] = 0xFEFEFE;
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
		textureOffsetX = (int)(ray->wallHitY * g_texture[index].width / g_tile_size) % g_texture[index].width;
	else
		textureOffsetX = (int)(ray->wallHitX * g_texture[index].width / g_tile_size) % g_texture[index].width;
	drawCeiling(wall, columnId);
	while (wall->wallTop < wall->wallBottom)
	{
		distanceFromTop = wall->wallTop + (wall->wallStripHeight / 2) - (g_window_height / 2);
		textureOffsetY = distanceFromTop * ((float)g_texture[index].height / wall->wallStripHeight);
		textureColor = g_texture[index].wallTexture[(g_texture[index].width * textureOffsetY) + textureOffsetX];
		/* if (textureColor != 0x000000) */
		g_image_data[(wall->wallTop * g_window_width) + columnId] = textureColor;
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
	if (!g_mlx_ptr)
	{
		printf("la mlx vaut null dans get_texture\n");
		exit(freeAll(ERROR));
	}
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
