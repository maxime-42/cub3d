#include "cub3d.h"

int			keyPressed(int keyCode)
{
	if (keyCode == UP_ARROW)
		g_player.walkDirection = +1;
	else if (keyCode == DOWN_ARROW)
        g_player.walkDirection = -1;
	else if (keyCode == RIGHT_ARROW)
        g_player.turnDirection = +1;
	else if (keyCode == LEFT_ARROW)
		g_player.turnDirection = -1;
	else if (keyCode == QUIT)
		exit(freeAll(SUCCESS));
	else if (keyCode == TRANSLATION_RIGHT)
	{
		g_player.translation = 1;
		g_player.walkDirection = +1;
	}
	else if (keyCode == TRANSLATION_LEFT)
	{
		g_player.translation = -1;
		g_player.walkDirection = -1;
	}
	return (0);
}

int			keyRelease(int keyCode)
{
    if (keyCode == UP_ARROW)
		g_player.walkDirection = 0;
	else if (keyCode == DOWN_ARROW)
		g_player.walkDirection = 0;
	else if (keyCode == RIGHT_ARROW)
		g_player.turnDirection = 0;
	else if (keyCode == LEFT_ARROW)
		g_player.turnDirection = 0;
	else if (keyCode == TRANSLATION_RIGHT || keyCode == TRANSLATION_LEFT)
	{
		g_player.translation = 0;
		g_player.walkDirection = 0;
	}
	return (0);
}
