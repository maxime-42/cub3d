/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utile2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 18:43:58 by lenox             #+#    #+#             */
/*   Updated: 2020/08/07 18:46:55 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_spritedistance(t_sprite *sprite, t_player *player)
{
	int			id;

	id = 0;
	while (id < sprite->nb_sprite)
	{
		sprite->distance[id] = distance_between_points(player->x,
		player->y, sprite->x[id], sprite->y[id]);
		id++;
	}
}
