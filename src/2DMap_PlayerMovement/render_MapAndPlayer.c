#include "cub3d.h"

static void	square(int start, int size, int color)
{
	int	y;
	int	x;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			g_image_data[start++] = color;
		}
		start = start - x;
		start = start + g_width;
	}
}

void	renderMap(char **map)
{
	int	y;
	int	x;
	int	color;
	int	start;

	y = -1;
	color = 0;
	while (map[++y])
	{
		x = -1;
		start = 0;
		start = start + (g_width * TILE_SIZE * y);
		while (map[y][++x])
		{
			if (map[y][x] == '0' || ft_strchr("NSEW", map[y][x]))
				color = COLOR_FREE_SPACE;
			else
				color = COLOR_WALL_SPACE;
			square(start, TILE_SIZE, color);
			start += TILE_SIZE;
		}
	}
}

void	renderPlayer(t_player *player)
{
	int	py;
	int	px;
	int	line;

	square(player->x + (g_width * player->y), 10, 0x0078FF);
	py = player->y;
	px = player->x;
	line = -1;
	while (++line < 30)
	{
		px =  cos(player->rotationAngle) * line + player->x;
		py =  sin(player->rotationAngle) * line + player->y;
		g_image_data[px + (g_width * py)] = 0x0078FF;
	}
}
