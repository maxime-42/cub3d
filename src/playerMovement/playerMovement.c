#include "cub3d.h"

static int	player_Orientation_Angle(float angle)
{
	angle = normalizeAngle(angle);
	if ((angle > M_PI * 0.25) && (angle < 0.75 * M_PI))
		return (1);
	else if ((angle > M_PI * 1.25) && (angle < 1.75 * M_PI))
		return (1);
	return (0);
}

/* void	calculs_dir_and_plan_for_sprites(t_sprite *sprite, t_player *player) */
/* { */
/* 	float	dirangle; */
/* 	float	olddirx; */
/* 	float	oldplanx; */

/* 	olddirx = sprite->dirx; */
/* 	oldplanx = sprite->planx; */
/* 	dirangle = player.turndirection * player->rotationspeed; */
/* 	sprite->dirx = sprite->dirx * cos(dirangle) - sprite->diry * sin(dirangle); */
/* 	sprite->diry = olddirx * sin(dirangle) + sprite->diry * cos(dirangle); */
/* 	sprite->planx = sprite->planx * cos(dirangle) - sprite->plany * sin(dirangle); */
/* 	sprite->plany = oldplanx * sin(dirangle) + sprite->plany * cos(dirangle); */
/* 	/\* if (ft_iswall(newPlayerY, newPlayerX) == 0) *\/ */
/* 	/\* { *\/ */
/* 	/\* 	player->x = newplayerX; *\/ */
/* 	/\* 	player->y = newplayerY; *\/ */
/* 	/\* } *\/ */
/* } */

void		playerMovement(t_player *player)
{
	float	moveStep;
	float	newPlayerX;
	float	newPlayerY;
	int		PlayerOrientation;
	float	angle_angle;

	PlayerOrientation = player_Orientation_Angle(player->rotationAngle);
	player->rotationAngle += player->turnDirection * player->rotationSpeed;
	moveStep = player->walkDirection * player->moveSpeed;
	newPlayerX = player->x + cos(player->rotationAngle) * moveStep;
	newPlayerY = player->y + sin(player->rotationAngle) * moveStep;
	if (player->translation == -1 || player->translation == 1)
	{
		angle_angle = (M_PI * 0.5) - player->rotationAngle;
		if (PlayerOrientation == 1)
		{
			newPlayerX = player->x - cos(angle_angle) * moveStep;
			newPlayerY = player->y + sin(angle_angle) * moveStep;
		}
		else if (PlayerOrientation == 0)
		{
			newPlayerX = player->x + cos(angle_angle) * -moveStep;
			newPlayerY = player->y - sin(angle_angle) * -moveStep;
		}
	}
	/* calculs_dir_and_plan_for_sprites(sprite, player); */
	if (!hasWallAt(newPlayerY, newPlayerX))
	{
		player->y = newPlayerY;
		player->x = newPlayerX;
	}
}
