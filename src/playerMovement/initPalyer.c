#include "cub3d.h"

void	initPlayer()
{
	g_window_width = (int)ft_strlen(g_info->begin->content) * TILE_SIZE;
	g_window_height = g_info->height * TILE_SIZE;
	g_player.x = g_window_width - (g_window_width / 3) ; //position player en x
	g_player.y = (g_width / 13); //position player en y
	g_player.radius = 5;
	g_player.turnDirection = 0;
	g_player.walkDirection = 0;
	g_player.rotationAngle = M_PI / 2;
	g_player.moveSpeed = 2.0;
	g_player.rotationSpeed = 0.2 * (M_PI / 180);
}
