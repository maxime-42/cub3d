#include "cub3d.h"

static void		playerMove(int keyCode)
{
	t_player	*player;
	double		moveStep;
	int			tmpX;
	int			tmpY;

	player = &g_info->player;
	if (keyCode)
		player->rotationAngle += player->turnDirection * player->rotationSpeed;
	else if (!keyCode)
	{
		moveStep = player->walkDirection * player->moveSpeed;
		tmpX = player->x + cos(player->rotationAngle) * moveStep;
		tmpY = player->y + sin(player->rotationAngle) * moveStep;
		if (!hasWallAt(tmpY, tmpX))
		{
			player->y = tmpY;
			player->x = tmpX;
		}
	}
	drawMap(g_info->map);
	drawPlayer(&g_info->player);
	castAllRays();
	mlx_put_image_to_window(g_mlx_ptr, g_win_mlx, g_img_ptr, 0, 0);
}

int				keyPressed(int keyCode)
{
	t_player	*player;

	player = &g_info->player;
	if (keyCode == UP_ARROW)
		player->walkDirection += 1;
	else if (keyCode == DOW_ARROW)
		player->walkDirection -= 1;
	else if (keyCode == LEFT_ARROW)
		player->turnDirection -= 1;
	else if (keyCode == RIGHT_ARROW)
		player->turnDirection += 1;
	else if (keyCode == QUIT)
		exit(freeAll(SUCCESS));
	if (keyCode == LEFT_ARROW || keyCode == RIGHT_ARROW)
		playerMove(1);
	else if (keyCode == UP_ARROW || keyCode == DOW_ARROW)
		playerMove(0);
	return (0);
}

int				keyRelease(int keyCode)
{
	t_player *player;

	player = &g_info->player;
	if (keyCode == LEFT_ARROW)
		player->turnDirection = 0;
	else if (keyCode == RIGHT_ARROW)
		player->turnDirection = 0;
	else if (keyCode == UP_ARROW)
		player->walkDirection = 0;
	else if (keyCode == DOW_ARROW)
		player->walkDirection = 0;
	return (0);
}
