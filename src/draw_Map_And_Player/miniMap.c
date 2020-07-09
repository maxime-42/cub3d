#include "cub3d.h"

static	void	utilis(int *ly, int *lx, int j)
{
	int			y;
	int			x;

	y = -1;
	while (++y < TILE_SIZE * MINIMAP_SCALE_FACTOR)
	{
		x = -1;
		while (++x < TILE_SIZE * MINIMAP_SCALE_FACTOR)
		{
			g_image_data[*ly * WINDOW_WIDTH + *lx] = 0xFFFFFF;
			*lx += 1;
		}
		*ly += 1;
		*lx = j * TILE_SIZE * MINIMAP_SCALE_FACTOR;
	}
}

void		drawMap(char **map)
{
	int		y;
	int		x;
	int		lx;
	int		ly;

	y = -1;
	while (++y < MAP_NUM_ROWS)
	{
		x= -1;
		while (++x < MAP_NUM_COLS)
		{
			if (map[y][x] == '0' || ft_strchr("NSEW", map[y][x]))
			{
				lx = x * TILE_SIZE * MINIMAP_SCALE_FACTOR;
				ly = y * TILE_SIZE * MINIMAP_SCALE_FACTOR;
				utilis(&ly, &lx, x);
			}
		}
	}
}

static void	playerRect(int corX, int corY, int width, int height, int color)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < height)
	{
		while (j < width)
		{
			g_image_data[(i + corY - width/2) * WINDOW_WIDTH + (j + corX - height/2)] = color;
			j++;
		}
		j = 0;
		i++;
	}
}

static void		positionLine(int corY, int corX, float distance, int color, float angle)
{
	float	i;
	int		x;
	int		y;
	int		longeur;

	longeur = 0;
	i = 0;
	x = 0;
	y = 0;
	while (i < distance)
	{
		g_image_data[(corY + y) * WINDOW_WIDTH + (corX + x)]= color;
		x = cos(angle) * longeur;
		y = sin(angle) * longeur;
		longeur++;
		i++;
	}
}

void		drawPlayer(t_player *player)
{
	playerRect(player->x * MINIMAP_SCALE_FACTOR, player->y * MINIMAP_SCALE_FACTOR, player->radius, player->radius,  0x0078FF);
	positionLine(player->y *  MINIMAP_SCALE_FACTOR, player->x *MINIMAP_SCALE_FACTOR,
	20, 0xff0000, player->rotationAngle);
}
