#include "cub3d.h"

int	keyPressed(int keyCode, t_player *player, t_info *info)
{
	if (keyCode == UP_ARROW)
	{
		player->walkDirection += 1;
	}
	else if (keyCode == DOW_ARROW)
	{
		player->walkDirection -= 1;
	}
	else if (keyCode == LEFT_ARROW)
	{
		player->turnDirection -= 1;
	}
	else if (keyCode == RIGHT_ARROW)
	{
		player->turnDirection += 1;
	}
	else if (keyCode == QUIT)
	{
		exit(0);
	}
	if (keyCode == LEFT_ARROW || keyCode == RIGHT_ARROW)
	{
		player->rotationAngle += player->turnDirection * player->rotationSpeed;
		renderPlayer(player, &info->pixel, (char **)info->map);
		player->turnDirection = 0;
		printf("hello word\n");
	}
	(void)info;
	(void)player;
	return (0);
}
