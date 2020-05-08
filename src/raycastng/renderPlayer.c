#include "cub3d.h"

void	get_PositionPlayer(char **map, t_player *player)
{
	int	line;
	int	column;

	line = -1;
	while (map[++line])
	{
		column = -1;
		while (map[line][++column])
		{
			if (ft_strchr("NSEW",map[line][column]))
			{
				player->x = column;
				player->y = line;
				column++;
				return ;
			}
		}
	}
}

static void	drawLine(t_player *player, t_pixel *pixel)
{
	int	py;
	int 	px;
	int	line;

	py = player->y;
	px = player->x;
	line = -1;
	while (++line < 30)
	{
		px =  cos(player->rotationAngle) * line;
		py =  sin(player->rotationAngle) * line;
		mlx_pixel_put(pixel->mlx_ptr, pixel->win_mlx, pixel->x + px, pixel->y + py, pixel->color);
	}
}

void	renderPlayer(t_player *player, t_pixel *pixel, char **map)
{
	get_PositionPlayer(map, player);
	pixel->x = player->x;
	pixel->y = player->y;
	pixel->color = 5373696;
	pixel->size = player->radius;
	my_pixel_put(pixel);
	drawLine(player, pixel);
	(void)player;
	(void)pixel;
	(void)map;
}
