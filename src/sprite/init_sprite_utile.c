#include "cub3d.h"

int	count_sprite(char **map)
{
	int	i;
	int	j;
	int	nb_sprite;


	i = -1;
	nb_sprite = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '2')
			{
				nb_sprite++;
			}
			j++;
		}
	}
	return (nb_sprite);
}

void	ft_mallocsprite(t_sprite *sprite)
{
	if (!(sprite->x = malloc(sizeof(float) * sprite->nb_sprite)))
	{
		ft_putstr_fd("Error\nFailer malloc\n", STDOUT);
		freeAll(ERROR);
	}
	if (!(sprite->y = malloc(sizeof(float) * sprite->nb_sprite)))
	{
		ft_putstr_fd("Error\nFailer malloc\n", STDOUT);
		freeAll(ERROR);
	}
	if (!(sprite->distance = (float *)malloc(sizeof(float) * sprite->nb_sprite)))
	{
		ft_putstr_fd("Error\nFailer malloc\n", STDOUT);
		freeAll(ERROR);	  
	}
	if (!(sprite->buffer = malloc(sizeof(float) * g_window_width)))
	{
		ft_putstr_fd("Error\nFailer malloc\n", STDOUT);
		freeAll(ERROR);	  
	}
	ft_bzero(sprite->buffer, sizeof(float) * g_window_width);
}
