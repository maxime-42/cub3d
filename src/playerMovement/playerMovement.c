#include "cub3d.h"

int			hasWallAt(float y, float x)
{
	int		mapGridIndexX;
	int		mapGridIndexY;

	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
	{
		return (1);
	}
	mapGridIndexX = floor(x / TILE_SIZE);
	mapGridIndexY = floor(y / TILE_SIZE);
	return (g_map[mapGridIndexY][mapGridIndexX] != '0');
}

int				keyPressed(int keyCode)
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
	return (0);
}

int				keyRelease(int keyCode)
{
    if (keyCode == UP_ARROW)
        g_player.walkDirection = 0;
	else if (keyCode == DOWN_ARROW)
		g_player.walkDirection = 0;
	else if (keyCode == RIGHT_ARROW)
		g_player.turnDirection = 0;
	else if (keyCode == LEFT_ARROW)
		g_player.turnDirection = 0;
	return (0);
}

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
