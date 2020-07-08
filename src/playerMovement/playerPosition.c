#include "cub3d.h"

void		coordinatePlayer(t_player *player)
{
	int		x;
	int		y;

	y = -1;
	while (g_map[++y])
	{
		x = -1;
		while (g_map[y][++x])
		{
			if (g_map[y][x] == 'N' || g_map[y][x] == 'S' ||
			g_map[y][x] == 'W' || g_map[y][x] == 'E')
			{
				player->x = TILE_SIZE * x;
				player->y = TILE_SIZE * y;
				player->position = g_map[y][x];
			}
		}
	}
}

void		playerPosition(t_player *player)
{
	coordinatePlayer(player);
	if (player->position == 'N')
		player->rotationAngle = (M_PI / 2) * 3;
	else if (player->position == 'W')
		player->rotationAngle = (M_PI / 2) * 2;
	else if (player->position == 'E')
		player->rotationAngle = (M_PI / 2) * 4;
	else if (player->position == 'S')
		player->rotationAngle = (M_PI / 2);
}
