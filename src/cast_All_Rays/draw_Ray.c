#include "cub3d.h"

void		draw_Ray(double angle, float lenght, int color)
{
	int		py;
	int		px;
	int		line;

	line = -1;
	py = 0;
	px = 0;
	while (++line < lenght)
	{
		g_image_data[px + ((WINDOW_WIDTH) * py)] = color;
		px = cos(angle) * line + g_player.x;
		py = sin(angle) * line + g_player.y;
	}
}

void		drawline(int corY, int corX, float distance, int color, float angle)
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
