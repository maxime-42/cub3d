#include "cub3d.h"

void			playerMovement(void)
{
	float		moveStep;
	float		newPlayerX;
	float		newPlayerY;

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


void	ft_movePlayer()
{
	float moveStep;

	float newX = 0;
	float newY = 0;

	g_player.rotationAngle += g_player.turnDirection * g_player.rotationSpeed;
	moveStep = g_player.walkDirection * g_player.moveSpeed;

	/* printf("g_player.turnDirection = %d\n", g_player.turnDirection); */
	/* printf("g_player.rotationAngle = %f\n", g_player.rotationAngle); */
	//normalizeAngle(param);

	newX = g_player.x + cos(g_player.rotationAngle) * moveStep;
	newY = g_player.y + sin(g_player.rotationAngle) * moveStep;

	if(hasWallAt(newY, newX) == 0)
	{
		g_player.x = newX;
		g_player.y = newY;
	}
}
