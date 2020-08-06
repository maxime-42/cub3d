/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerMovement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 10:53:26 by lenox             #+#    #+#             */
/*   Updated: 2020/08/06 14:26:31 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		player_orientation_angle(float angle)
{
	angle = normalize_angle(angle);
	if ((angle > M_PI * 0.25) && (angle < 0.75 * M_PI))
		return (1);
	else if ((angle > M_PI * 1.25) && (angle < 1.75 * M_PI))
		return (1);
	return (0);
}

static void		update_position(t_player *player, float y,
								float x, t_sprite *sprite)
{
	float		olddirx;
	float		oldplanx;
	float		vectangle;

	olddirx = sprite->dirx;
	oldplanx = sprite->planx;
	vectangle = player->turnDirection * player->rotationSpeed;
	sprite->dirx = sprite->dirx * cos(vectangle) - sprite->diry *
	sin(vectangle);
	sprite->diry = olddirx * sin(vectangle) + sprite->diry * cos(vectangle);
	sprite->planx = sprite->planx * cos(vectangle) - sprite->plany *
	sin(vectangle);
	sprite->plany = oldplanx * sin(vectangle) + sprite->plany * cos(vectangle);
	if (!has_wall_at(y, x))
	{
		player->y = y;
		player->x = x;
	}
}

void			player_movement(t_player *player)
{
	float		move_step;
	float		new_player_x;
	float		new_player_y;
	int			player_orientation;

	player_orientation = player_orientation_angle(player->rotationAngle);
	player->rotationAngle += player->turnDirection * player->rotationSpeed;
	move_step = player->walkDirection * player->moveSpeed;
	new_player_x = player->x + cos(player->rotationAngle) * move_step;
	new_player_y = player->y + sin(player->rotationAngle) * move_step;
	if (player->translation == -1 || player->translation == 1)
	{
		player->angle_angle = (M_PI * 0.5) - player->rotationAngle;
		if (player_orientation == 1)
		{
			new_player_x = player->x - cos(player->angle_angle) * move_step;
			new_player_y = player->y + sin(player->angle_angle) * move_step;
		}
		else if (player_orientation == 0)
		{
			new_player_x = player->x + cos(player->angle_angle) * -move_step;
			new_player_y = player->y - sin(player->angle_angle) * -move_step;
		}
	}
	update_position(player, new_player_y, new_player_x, &g_sprite);
}
