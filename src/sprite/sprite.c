/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:20:01 by lenox             #+#    #+#             */
/*   Updated: 2020/08/06 15:22:13 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

static float	ft_gettransformy(t_sprite *sprite, t_player *player, int id)
{
	float	spritex;
	float	spritey;
	float	invdet;
	float	transformx;
	float	transformy;

	spritex = sprite->x[id] - player->x;
	spritey = sprite->y[id] - player->y;
	invdet = 1.0 / (sprite->planx * sprite->diry - sprite->dirx * sprite->plany);
	transformx = invdet * (sprite->diry * spritex - sprite->dirx * spritey);
	transformy = invdet * (-sprite->plany * spritex + sprite->planx * spritey);
	sprite->spritescreenx = (int)((g_window_width / 2) *
	(1 + -transformx / transformy));
	return (transformy);
}

static void	ft_switch(t_sprite *sprite, int i, int j)
{
	float	temp_dist;
	float	temp_y;
	float	temp_x;

	temp_dist = sprite->distance[j];
	temp_x = sprite->x[j];
	temp_y = sprite->y[j];
	sprite->distance[j] = sprite->distance[i];
	sprite->x[j] = sprite->x[i];
	sprite->y[j] = sprite->y[i];
	sprite->distance[i] = temp_dist;
	sprite->x[i] = temp_x;
	sprite->y[i] = temp_y;
}

static void	ft_sortsprite(t_sprite *sprite)
{
	int	j;
	int	i;

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

static void	ft_spritedistance(t_sprite *sprite, t_player *player)
{
	int	id;

	id = 0;
	while (id < sprite->nb_sprite)
	{
		sprite->distance[id] = distance_between_points(player->x,
		player->y, sprite->x[id], sprite->y[id]);
		id++;
	}
}

static void	ft_zero(t_sprite *sprite)
{
	sprite->drawstartx = 0;
	sprite->drawendx = 0;
	sprite->drawstarty = 0;
	sprite->drawendy = 0;
	sprite->spritescreenx = 0;
}

void		ft_putsprite(t_sprite *sprite, t_player *player)
{
	float	distanceprojection;
	float	sprite_size;
	int	id;
	float	transformy;

	id = 0;
	ft_spritedistance(sprite, player);
	ft_sortsprite(sprite);
	while (id < sprite->nb_sprite)
	{
		distanceprojection = (g_window_width / 2) / tan(g_fov_angle / 2);
		sprite_size = (g_tile_size * 0.5 / sprite->distance[id]) *
		distanceprojection;
		ft_zero(sprite);
		if (ft_spritevisible(sprite, player, id, sprite_size) == 1)
		{
			transformy = ft_gettransformy(sprite, player, id);
			ft_getstart(sprite, sprite_size, transformy);
			ft_drawsprite(sprite, transformy, sprite_size);
		}
		id++;
	}
}
