#include "cub3d.h"

static void	playerRect(int corX, int corY, int width, int height, int color)
{
	int i;
	int j;

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

void		drawPlayer(t_player *player)
{
	/* int	color; */

	/* color = 0x0078FF; */
	/* drawRect(g_player.x + (WINDOW_WIDTH * g_player.y), g_player.radius, 0x0078FF); */
	playerRect(player->x * MINIMAP_SCALE_FACTOR, player->y * MINIMAP_SCALE_FACTOR, player->radius, player->radius,  0x0078FF);
	//line d'orientation du joueur
	/* draw_Ray(player->rotationAngle, TILE_SIZE * 2, 0x0078FF); */
	/* drawline(player->y, player->x, 30, color, player->rotationAngle); */
}
