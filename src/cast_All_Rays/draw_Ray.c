#include "cub3d.h"

void		draw_Ray(double angle, float lenght)
{
	int		py;
	int		px;
	int		line;

	line = -1;
	py = 0;
	px = 0;
	while (++line < lenght)
	{
		g_image_data[px + (g_width * py)] = 0xF10B0B;
		px = cos(angle) * line + g_player.x;
		py = sin(angle) * line + g_player.y;
	}
}


