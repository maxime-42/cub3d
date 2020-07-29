#include "cub3d.h"

static	void	draw_map_utile(int *ly, int *lx, int j, int color)
{
	int	y;
	int	x;

	y = -1;
	while (++y < g_tile_size * MINIMAP_SCALE_FACTOR)
	{
		x = -1;
		while (++x < g_tile_size * MINIMAP_SCALE_FACTOR)
		{
			g_image_data[*ly * g_window_width + *lx] = color;
			*lx += 1;
		}
		*ly += 1;
		*lx = j * g_tile_size * MINIMAP_SCALE_FACTOR;
	}
}

static	void	drawMap(char **map)
{
	int		y;
	int		x;
	int		lx;
	int		ly;

	y = -1;
	while (++y < g_map_num_rows)
	{
		x= -1;
		while (++x < g_map_num_cols)
		{
			if (map[y][x] == '2' || map[y][x] == '0' || ft_strchr("NSEW", map[y][x]))
			{
				lx = x * g_tile_size * MINIMAP_SCALE_FACTOR;
				ly = y * g_tile_size * MINIMAP_SCALE_FACTOR;
				if (map[y][x] == '2')
					draw_map_utile(&ly, &lx, x, 0xFF0000);
				else
					draw_map_utile(&ly, &lx, x, 0xFFFFFF);  
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
			g_image_data[(i + corY - width/2) * g_window_width + (j + corX - height/2)] = color;
			j++;
		}
		j = 0;
		i++;
	}
}

static void	orientation_line(int corY, int corX, float distance, int color, float angle)
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
		g_image_data[(corY + y) * g_window_width + (corX + x)]= color;
		x = cos(angle) * longeur;
		y = sin(angle) * longeur;
		longeur++;
		i++;
	}
}

void		miniMap(t_player *player, char **map)
{
	drawMap(map);
	playerRect(player->x * MINIMAP_SCALE_FACTOR, player->y * MINIMAP_SCALE_FACTOR, player->radius, player->radius, 0x0078FF);
	orientation_line(player->y * MINIMAP_SCALE_FACTOR, player->x * MINIMAP_SCALE_FACTOR,
	10, 0xff0000, player->rotationAngle);
}
