#include "cub3d.h"

void	my_pixel_put(t_pixel *pixel)
{
	int	y;
	int	x;
	int	tmp_j;

	y = -1;
	tmp_j = pixel->x;
	while (++y < pixel->size)
	{
		x = -1;
		pixel->x = tmp_j;
		while (++x <  pixel->size)
		{
			mlx_pixel_put(pixel->mlx_ptr, pixel->win_mlx,
			pixel->x, pixel->y, pixel->color);
			pixel->x++;
		}
		pixel->y++;
	}
}

void	renderMap(char **map, t_pixel *pixel)
{
	int	y;
	int	x;
	int	py;
	int	px;

	y = -1;
	while (map[++y])
	{
		x = -1;
		py = pixel->size * y;
		if (py > 0)
			py -= y;
		while (map[y][++x])
		{
			pixel->color = (map[y][x] == '0') ? 16775936 : 16711680;
			px = TILE_SIZE * x;
			if (px > 0)
				px -= x;
			pixel->x = x + px;
			pixel->y = y + py;
			my_pixel_put(pixel);
		}
    }
}

/* static void	drawLine(t_info *info, t_player *player, int color) */
/* { */
/* 	int	y; */
/* 	int 	x; */
/* 	int	line; */

/* 	y = player->y; */
/* 	x = player->x; */
/* 	line = -1; */
/* 	while (++line < 30) */
/* 	{ */
/* 		x +=  cos(player->rotationAngle) * line; */
/* 		y +=  sin(player->rotationAngle) * line; */
/* 		mlx_pixel_put(info->mlx_ptr, info->win_mlx, x, y, color); */
/* 	} */
/* } */

void	renderPlayer(t_info *info)
{
	/* double	limitX; */
	/* double	limitY; */
	/* limitX = info->player.x +  cos(info->player.rotationAngle) * TILE_SIZE; */
	/* limitY = info->player.y +  sin(info->player.rotationAngle) * TILE_SIZE; */
	/* printf("%f\n", limitX); */
	/* my_pixel_put(info, info->player.x, info->player.y, 7667456); */
	/* drawLine(info, &info->player, 7667456); */
	/* mlx_pixel_put(info->mlx_ptr, info->win_mlx, limitX, limitY, 15466751); */
	/* drawLine(info, &info->player); */
	(void)info;
}
