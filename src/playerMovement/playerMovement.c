#include "cub3d.h"

void		playerMovement(t_player *player)
{
	float	moveStep;
	float	newPlayerX;
	float	newPlayerY;

	newPlayerY = 0;
	newPlayerX = 0;
	player->rotationAngle += player->turnDirection * player->rotationSpeed;
	moveStep = player->walkDirection * player->moveSpeed;
	newPlayerX = player->x + cos(player->rotationAngle) * moveStep;
	newPlayerY = player->y + sin(player->rotationAngle) * moveStep;
	if (!hasWallAt(newPlayerY, newPlayerX))
	{
		player->y = newPlayerY;
		player->x = newPlayerX;
	}
}
