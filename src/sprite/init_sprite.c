#include "cub3d.h"

static void	load_ptr_and_data_sprite(t_sprite *sprite)
{
	int	bpp;
	int	size_line;
	int	endian;

	sprite->ptr = mlx_xpm_file_to_image(g_mlx_ptr, sprite->path, &sprite->width, &sprite->height);
	if (!sprite->ptr)
	{
		ft_putstr_fd("Error\nFailer get ptr sprite\n", STDOUT);
		exit(freeAll(ERROR));
	}
	sprite->data = (int *)mlx_get_data_addr(sprite->ptr, &bpp, &size_line, &endian);
	if (!sprite->data)
	{
		ft_putstr_fd("Error\nFailer get image sprite\n", STDOUT);
		exit(freeAll(ERROR));
	}
}

static	void	put_to_zero(t_sprite *sprite)
{
	sprite->angle = 0;
	sprite->ptr = 0;
	sprite->data = 0;
	sprite->bpp = 0;
	sprite->endian = 0;
	sprite->size_l = 0;
	sprite->width = 0;
	sprite->height = 0;
}

static void	init_position_sprite(t_sprite *sprite, char **map)
{
	int	i;
	int	j;
	int	id;

	id = 0;
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '2')
			{
				sprite->x[id] = j * g_tile_size + g_tile_size / 2;
				sprite->y[id] = i * g_tile_size + g_tile_size / 2;
				sprite->distance[id] = 0;
				id++;
			}
			j++;
		}
	}
}

static void	init_vecteur(t_sprite *sprite, char player_position)
{
	if (player_position == 'E')
	{
		sprite->dirx = 1;
		sprite->diry = 0;
		sprite->planx = 0;
		sprite->plany = -0.6;
	}
	else if (player_position == 'S')
	{
		sprite->dirx = 0;
		sprite->diry = 1;
		sprite->planx = 0.6;
		sprite->plany = 0;
	}
	else if (player_position == 'W')
	{
		sprite->dirx = -1;
		sprite->diry = 0;
		sprite->planx = 0;
		sprite->plany = 0.6;
	}
	else if (player_position ==  'N')
	{
		sprite->dirx = 0;
		sprite->diry = -1;
		sprite->planx = -0.6;
		sprite->plany = 0;
	}
}

 void		init_sprite(t_sprite *sprite, char **map, char player_position)
{

	sprite->nb_sprite = count_sprite(map);
	ft_mallocsprite(sprite);
	put_to_zero(sprite);
	load_ptr_and_data_sprite(sprite);
	init_position_sprite(sprite, map);
	init_vecteur(sprite, player_position);
}
