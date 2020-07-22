#include "cub3d.h"

static void		coordinate_player(t_player *player)
{
	int			x;
	int			y;

	y = -1;
	while (g_map[++y])
	{
		x = -1;
		while (g_map[y][++x])
		{
			if (g_map[y][x] == 'N' || g_map[y][x] == 'S' ||
			g_map[y][x] == 'W' || g_map[y][x] == 'E')
			{
				player->x = g_tile_size * x;
				player->y = g_tile_size * y;
				player->position = g_map[y][x];
			}
		}
	}
}

static void		player_position(t_player *player)
{
	coordinate_player(player);
	if (player->position == 'N')
		player->rotationAngle = (M_PI / 2) * 3;
	else if (player->position == 'W')
		player->rotationAngle = (M_PI / 2) * 2;
	else if (player->position == 'E')
		player->rotationAngle = (M_PI / 2) * 4;
	else if (player->position == 'S')
		player->rotationAngle = (M_PI / 2);
}

void			init_player(t_player *player)
{
	player->radius = 5;
	player->turnDirection = 0;
	player->walkDirection = 0;
	player_position(player);
	player->moveSpeed = 2;
	player->rotationSpeed = 1 * (M_PI / 180);
}