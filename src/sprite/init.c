#include "cub3d.h"

static void	get_ptr_and_data(t_sprite *sprite)
{
	int	bpp;
	int	size_line;
	int	endian;

	sprite->ptr = mlx_xpm_file_to_image(g_mlx_ptr, sprite->path, &sprite->width, &sprite->height);
	sprite->data = (int *)mlx_get_data_addr(sprite->ptr, &bpp, &size_line, &endian);
	if (!sprite->ptr)
	{
		ft_putstr_fd("Error\nFailer get sprite ptr\n", STDOUT);
		exit(freeAll(ERROR));
	}
	printf("ptr sprite success\n");
	printf("%s\n", sprite->path);
}


static void	position_sprite(t_sprite *sprite, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '2')
			{
				sprite->x = j * TILE_SIZE + TILE_SIZE / 2;
				sprite->y = i * TILE_SIZE + TILE_SIZE / 2;
			}
			j++;
		}
	}
	sprite->angle = 0;
	sprite->data = 0;
	sprite->bpp = 0;
	sprite->endian = 0;
	sprite->size_l = 0;
	sprite->width = 0;
	sprite->height = 0;
}

static void	init_vecteur(t_sprite *sprite, float rotationangle)
{
	if (rotationangle == ANGLE_EAST)
	{
		sprite->dirx = 1;
		sprite->diry = 0;
		sprite->planx = 0;
		sprite->plany = -0.6;
	}
	if (rotationangle == ANGLE_DOWN)
	{
		sprite->dirx = 0;
		sprite->diry = 1;
		sprite->planx = 0.6;
		sprite->plany = 0;
	}
	if (rotationangle == ANGLE_WEST)
	{
		sprite->dirx = -1;
		sprite->diry = 0;
		sprite->planx = 0;
		sprite->plany = 0.6;
	}
	if (rotationangle == ANGLE_UP)
	{
		sprite->dirx = 0;
		sprite->diry = -1;
		sprite->planx = -0.6;
		sprite->plany = 0;
	}
}

void		init_sprite(t_sprite *sprite, char **map, float rotationangle)
{
	get_ptr_and_data(sprite);
	position_sprite(sprite, map);
	init_vecteur(sprite, rotationangle);
}
