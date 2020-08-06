/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_utile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:43:49 by lenox             #+#    #+#             */
/*   Updated: 2020/08/06 15:46:51 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_vecteur_north(t_sprite *sprite)
{
	sprite->dirx = 0;
	sprite->diry = -1;
	sprite->planx = -0.6;
	sprite->plany = 0;
}

int		count_sprite(char **map)
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
		free_all(ERROR);
	}
	if (!(sprite->y = malloc(sizeof(float) * sprite->nb_sprite)))
	{
		ft_putstr_fd("Error\nFailer malloc\n", STDOUT);
		free_all(ERROR);
	}
	if (!(sprite->distance = (float *)malloc(sizeof(float) *
	sprite->nb_sprite)))
	{
		ft_putstr_fd("Error\nFailer malloc\n", STDOUT);
		free_all(ERROR);
	}
	if (!(sprite->buffer = malloc(sizeof(float) * g_window_width)))
	{
		ft_putstr_fd("Error\nFailer malloc\n", STDOUT);
		free_all(ERROR);
	}
	ft_bzero(sprite->buffer, sizeof(float) * g_window_width);
}
