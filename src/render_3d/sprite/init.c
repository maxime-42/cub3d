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

static void	position_sprite(t_sprite *sprite, char **map)
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
			}
			j++;
		}
	}
}

static void	init_vecteur(t_sprite *sprite, float rotationangle)
{
  //printf("rotationangle = %f\n", rotationangle);
		/* printf("rotationangle = %f\n", rotationangle); */
		/* printf("ANGLE_UP = %f\n", (float)ANGLE_UP); */
  
	/* if (rotationangle == ANGLE_EAST) */
	/* { */
	/* 	sprite->dirx = 1; */
	/* 	sprite->diry = 0; */
	/* 	sprite->planx = 0; */
	/* 	sprite->plany = -0.6; */
	/* } */
	/* else if (rotationangle == ANGLE_DOWN) */
	/* { */
	/* 	sprite->dirx = 0; */
	/* 	sprite->diry = 1; */
	/* 	sprite->planx = 0.6; */
	/* 	sprite->plany = 0; */
	/* } */
	/* else if (rotationangle == ANGLE_WEST) */
	/* { */
	/* 	sprite->dirx = -1; */
	/* 	sprite->diry = 0; */
	/* 	sprite->planx = 0; */
	/* 	sprite->plany = 0.6; */
	/* } */
  	printf("rotationangle = %f\n", rotationangle);
	printf("ANGLE_UP = %f\n", ANGLE_UP);

	if (rotationangle ==  1.5 * M_PI)
	{
		printf("hellow\n");
		sprite->dirx = 0;
		sprite->diry = -1;
		sprite->planx = -0.6;
		sprite->plany = 0;
	}
	/* else */
	/* { */
	/* } */

}

 void		init_sprite(t_sprite *sprite, char **map, float rotationangle)
{

	sprite->nb_sprite = count_sprite(map);
	ft_mallocsprite(sprite);
	put_to_zero(sprite);
	load_ptr_and_data_sprite(sprite);
	position_sprite(sprite, map);
	init_vecteur(sprite, rotationangle);
	/* printf("sprite->planx = %f\n", sprite->planx); */
	/* printf("sprite->diry = %f\n", sprite->diry); */
	/* printf("sprite->dirx = %f\n", sprite->dirx); */
	/* printf("sprite->plany = %f\n", sprite->plany); */

}
