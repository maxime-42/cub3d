#include "cub3d.h"

int				keyPressed(int keyCode)
{
	if (keyCode == UP_ARROW)
		g_player.walkDirection += 1;
	else if (keyCode == DOW_ARROW)
		g_player.walkDirection -= 1;
	else if (keyCode == LEFT_ARROW)
		g_player.turnDirection -= 1;
	else if (keyCode == RIGHT_ARROW)
		g_player.turnDirection += 1;
	else if (keyCode == QUIT)
		exit(freeAll(SUCCESS));
	return (0);
}

int				keyRelease(int keyCode)
{
	if (keyCode == LEFT_ARROW)
		g_player.turnDirection = 0;
	else if (keyCode == RIGHT_ARROW)
		g_player.turnDirection = 0;
	else if (keyCode == UP_ARROW)
		g_player.walkDirection = 0;
	else if (keyCode == DOW_ARROW)
		g_player.walkDirection = 0;
	return (0);
}
