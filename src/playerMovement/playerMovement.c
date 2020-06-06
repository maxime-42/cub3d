#include "cub3d.h"

void			playerMovement(void)
{
	float		moveStep;
	int			newPlayerX;
	int			newPlayerY;

	newPlayerY = 0;
	newPlayerX = 0;
	g_player.rotationAngle += g_player.turnDirection * g_player.rotationSpeed;
	moveStep = g_player.walkDirection * g_player.moveSpeed;
	newPlayerX = g_player.x + cos(g_player.rotationAngle) * moveStep;
	newPlayerY = g_player.y + sin(g_player.rotationAngle) * moveStep;
	if (!hasWallAt(newPlayerY, newPlayerX))
	{
		g_player.y = newPlayerY;
		g_player.x = newPlayerX;
	}
	(void)newPlayerX;
	(void)newPlayerY;
}
