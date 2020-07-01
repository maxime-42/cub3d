#include "cub3d.h"

void	drawRect(int corX, int corY, int width, int height, int color)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < height)
	{
		while (j < width)
		{
			g_image_data[(i + corY) * WINDOW_WIDTH + (j + corX)] = color;
			j++;
		}
		j = 0;
		i++;
	}
}
