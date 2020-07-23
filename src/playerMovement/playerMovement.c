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

void		ft_updatevect(t_player *player, t_sprite *sprite)
{
	float	olddirx;
	float	oldplanx;
	float	vectangle;

	olddirx = sprite->dirx;
	oldplanx = sprite->planx;
	vectangle = player->turnDirection * player->rotationSpeed;
	sprite->dirx = sprite->dirx * cos(vectangle) - sprite->diry * sin(vectangle);
	sprite->diry = olddirx * sin(vectangle) + sprite->diry * cos(vectangle);
	sprite->planx = sprite->planx * cos(vectangle) - sprite->plany * sin(vectangle);
	sprite->plany = oldplanx * sin(vectangle) + sprite->plany * cos(vectangle);
}

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
	ft_updatevect(player, &g_sprite);
	if (!hasWallAt(newPlayerY, newPlayerX))
	{
		player->y = newPlayerY;
		player->x = newPlayerX;
	}
}
