#include "cub3d.h"

void	drawPlayer(t_player *player)
{
	int	color;

	color = 0x0078FF;
	/* drawRect(g_player.x + (WINDOW_WIDTH * g_player.y), g_player.radius, 0x0078FF); */
	Rect(player->x * MINIMAP_SCALE_FACTOR, player->y * MINIMAP_SCALE_FACTOR, player->radius, player->radius,  0x0078FF);
	//line d'orientation du joueur
	/* draw_Ray(player->rotationAngle, TILE_SIZE * 2, 0x0078FF); */
	drawline(player->y, player->x, 30, color, player->rotationAngle);
}
