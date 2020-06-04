#include "cub3d.h"

/*drawG_Player:  representer le joueur par un carré
*/
void	drawPlayer()
{
	int	py;
	int	px;
	int	line;

	//je dessine le jouere ici il est representer par un carré
	drawSquare(g_player.x + (g_width * g_player.y), g_player.radius, 0x0078FF);
	line = -1;
	//dans cette boucle je dessine le rayon d'orientation du joueur
	while (++line < TILE_SIZE * 2)
	{
		px = cos(g_player.rotationAngle) * line + g_player.x;
		py = sin(g_player.rotationAngle) * line + g_player.y;
		g_image_data[px + (g_width * py)] = 0x0078FF;
	}
	(void)py;
	(void)line;
	(void)px;
	(void)g_player;
}
