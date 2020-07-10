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
int			player_Orientation_Angle(float angle)
{
		angle = normalizeAngle(angle);
	if ((angle > M_PI * 0.25 && angle < 0.75 * M_PI) || (angle > M_PI * 1.25 && angle < 1.75 * M_PI))
		{
			return (1);
		}
		return (0);

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
	if (player->translation == 1 || player->translation == -1)
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
	if (!hasWallAt(newPlayerY, newPlayerX))
	{
		player->y = newPlayerY;
		player->x = newPlayerX;
	}
}

void		initPlayer(t_player *player)
{
	player->x = WINDOW_WIDTH / 2;
	player->y = WINDOW_HEIGHT / 2;
	player->radius = 5;
	player->turnDirection = 0;
	player->walkDirection = 0;
	playerPosition(player);
	player->moveSpeed = 5;
	player->rotationSpeed = 5 * (M_PI / 180);
}
