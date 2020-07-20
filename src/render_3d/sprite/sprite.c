#include "cub3d.h"

float	ft_gettransformy(t_sprite *sprite_size, int id, float sprite_size)
{
	float	spritex;
	float	spritey;
	float	invdet;
	float	transformx;
	float	transformy;

	spritex = sprite->x[id] - player->x;
	spritey = sprite->y[id] - player->y;
	invdet = 1.0 / (sprite->planx * sprite->diry
		- sprite->dirx * sprite->plany);
	transformx = invdet * (sprite->diry * spritex
		- sprite->dirx * spritey);
	transformy = invdet * (-param->player.plany * spritex
		+ sprite.planx * spritey);
	sprite->spritescreenx = (int)((sprite->win_width / 2) *
		(1 + -transformx / transformy));
	return (transformy);
}

void	ft_switch(t_sprite *sprite, int i, int j)
{
	float	temp_dist;
	float	temp_y;
	float	temp_x;

	temp_dist = sprite->distance[j];
	temp_x = sprite->x[j];
	temp_y = sprite->y[j];
	sprite->distance[j] = sprite->distance[i];
	sprite.x[j] = sprite->x[i];
	sprite->y[j] = sprite->y[i];
	sprite->distance[i] = temp_dist;
	sprite->x[i] = temp_x;
	sprite->y[i] = temp_y;
}


void	ft_sortsprite(t_sprite *sprite)
{
	int		j;
	int		i;

	i = -1;
	while (i++ < sprite->nb_sprite)
	{
		j = i + 1;
		while (j < sprite->nb_sprite)
		{
			if (sprite->distance[j] > sprite->distance[i])
				ft_switch(sprite, i, j);
			j++;
		}
	}
}

void	ft_spritedistance(t_param *param)
{
	int id;

	id = 0;
	while (id < param->sprite.nb_sprite)
	{
		sprite->distanceB[id] = distanceBetweenPoints(player->x, player->y, sprite->x[id], sprite->y[id]);
		id++;
	}
}

void	ft_zero(t_sprite *sprite)
{
	sprite->drawstartx = 0;
	sprite->drawendx = 0;
	sprite->drawstarty = 0;
	sprite->drawendy = 0;
	sprite->spritescreenx = 0;
}

void	ft_putsprite(t_sprite *sprite)
{
	float	distanceprojection;
	float	sprite_size;
	int	id;
	float	transformy;

	id = 0;
	ft_spritedistance(sprite);
	ft_sortsprite(sprite);
	while (id < sprite->sprite.nb_sprite)
	{
		distanceprojection = (g_window_width / 2) / tan(g_fov_angle / 2);
		sprite_size = (sprite->tile_s * 0.5 /
			sprite->sprite.distance[id]) * distanceprojection;
		ft_zero(sprite);
		if (ft_spritevisible(sprite, id, sprite_size) == 1)
		{
			transformy = ft_gettransformy(sprite, id, sprite_size);
			ft_getstart(sprite, sprite_size);
			ft_drawsprite(sprite, transformy, sprite_size);
		}
		id++;
	}
}
