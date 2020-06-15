#include "cub3d.h"

void	initPlayer()
{
	g_player.x = WINDOW_WIDTH / 2;
	g_player.y = WINDOW_HEIGHT / 2;
	g_player.radius = 5;
	g_player.turnDirection = 0;
	g_player.walkDirection = 0;
	g_player.rotationAngle = M_PI / 2;
	g_player.moveSpeed = 5;
	g_player.rotationSpeed = 2 * (M_PI / 180);
}
