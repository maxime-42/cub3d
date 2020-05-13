#include "cub3d.h"

int	placeIsSafe(int y, int x)
{
	int	position;
	char	**map;

	map = (char **)g_info->map;
	printf("y == %d | x == %d\n", y, x);	
	y = y /  TILE_SIZE;
	x = x / TILE_SIZE;
	if (map[y][x] == '0')
	{
		printf("is safe\n");
		return (1);
	}
	(void)position;
	return (0);
}

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
		if (placeIsSafe(tmpY, tmpX))
		{
			player->y = tmpY;
			player->x = tmpX;
		}
	}
	renderMap(g_info->map);
	renderPlayer(&g_info->player);
	mlx_put_image_to_window(g_mlx_ptr, g_win_mlx, g_img_ptr, 0, 0);
}

int	keyPressed(int keyCode)
{
	t_player *player;

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


int	keyRelease(int keyCode)
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

/* static void	playerMove(int keyCode) */
/* { */
/* 	t_player *player; */
/* 	double moveStep; */

/* 	player = &g_info->player; */
/* 	if (keyCode) */
/* 		player->rotationAngle += player->turnDirection * player->rotationSpeed; */
/* 	else if (!keyCode) */
/* 	{ */
/* 		moveStep = player->walkDirection * player->moveSpeed; */
/* 		player->x += cos(player->rotationAngle) * moveStep; */
/* 		player->y += sin(player->rotationAngle) * moveStep; */
/* 	} */
/* 	renderMap(g_info->map); */
/* 	renderPlayer(&g_info->player); */
/* 	mlx_put_image_to_window(g_mlx_ptr, g_win_mlx, g_img_ptr, 0, 0); */
/* } */
