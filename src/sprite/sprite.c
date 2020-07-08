#include "cub3d.h"

static void	get_sprite(t_sprite *sprite)
{
	int		bpp;
	int		size_line;
	int		endian;

	sprite->sprite_ptr = mlx_xpm_file_to_image(g_mlx_ptr, sprite->path, &sprite->width, &sprite->height);
	sprite->wallSprite = (int *)mlx_get_data_addr(sprite->sprite_ptr, &bpp, &size_line, &endian);
	if (!sprite->sprite_ptr)
	{
		ft_putstr_fd("Error\nFailer sprite ptr\n", STDOUT);
		exit (freeAll(ERROR));
	}
}

void		put_sprite(t_ray *ray, int top, int wallStripHeight, int wallBottom, int columnId)
{
	int		textureOffsetX;
	int		textureOffsetY;
	int		spriteColor;
	int		distanceFromTop;

		get_sprite(&g_sprite);
		/* printf("g_sprite.height = %d\n", g_sprite.height); */
		/* printf("g_sprite.width = %d\n", g_sprite.width); */
		if (ray->wasHitVertical == 1)
			textureOffsetX = (int)(ray->wallHitY * g_sprite.width / TILE_SIZE) % g_sprite.width;
		else
			textureOffsetX = (int)(ray->wallHitX * g_sprite.width / TILE_SIZE) % g_sprite.width;
		while (top < wallBottom)
		{
			distanceFromTop = top + (wallStripHeight / 2) - (WINDOW_HEIGHT / 2);
			textureOffsetY = distanceFromTop * ((float)g_sprite.height / wallStripHeight);
			spriteColor = g_sprite.wallSprite[(g_sprite.width * textureOffsetY) + textureOffsetX];
			g_image_data[(top * WINDOW_WIDTH) + columnId] = spriteColor;
			top++;
		}
}
