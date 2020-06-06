#include "cub3d.h"

void	drawPlayer()
{
	//representer le joueur par un carré
	drawRect(g_player.x + (WINDOW_WIDTH * g_player.y), g_player.radius, 0x0078FF);
	//line d'orientation du joueur
	draw_Ray(g_player.rotationAngle, TILE_SIZE * 2, 0x0078FF);
}
