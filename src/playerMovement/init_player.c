#include "cub3d.h"

static void		coordinate_player(t_player *player)
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
				player->x = g_tile_size * x + g_tile_size / 2;
				player->y = g_tile_size * y + g_tile_size / 2;
				player->position = g_map[y][x];
			}
		}
	}
}

static void		player_position(t_player *player)
{
	coordinate_player(player);
	if (player->position == 'N')
		player->rotationAngle = ANGLE_UP;
	else if (player->position == 'W')
		player->rotationAngle = ANGLE_WEST;
	else if (player->position == 'E')
		player->rotationAngle = ANGLE_EAST;
	else if (player->position == 'S')
		player->rotationAngle = ANGLE_DOWN;
}

void			init_player(t_player *player)
{
	player->radius = 5;
	player->turnDirection = 0;
	player->walkDirection = 0;
	player_position(player);
	player->moveSpeed = 5;
	player->rotationSpeed = 3 * (M_PI / 180);
}
