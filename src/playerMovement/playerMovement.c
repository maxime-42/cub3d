#include "cub3d.h"

void			playerMovement(void)
{
	double		moveStep;
	int			tmpX;
	int			tmpY;

	tmpY = 0;
	tmpX = 0;
	g_player.rotationAngle += g_player.turnDirection * g_player.rotationSpeed;
	moveStep = g_player.walkDirection * g_player.moveSpeed;
	tmpX = g_player.x + cos(g_player.rotationAngle) * moveStep;
	tmpY = g_player.y + sin(g_player.rotationAngle) * moveStep;
	if (!hasWallAt(tmpY, tmpX))
	{
		g_player.y = tmpY;
		g_player.x = tmpX;
	}
}
