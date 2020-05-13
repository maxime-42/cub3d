#include "cub3d.h"

/* void	renderPlayer(t_player *player) */
/* { */
/* 	int	py; */
/* 	int	px; */
/* 	int	line; */

/* 	square(player->y, 10, 0x0078FF); */
/* 	py = player->y; */
/* 	px = player->x; */
/* 	line = -1; */
/* 	while (++line < 30) */
/* 	{ */
/* 		px = cos(player->rotationAngle) * line + player->x; */
/* 		py = sin(player->rotationAngle) * line + player->y; */
/* 		g_image_data[px + py] = 0x0078FF; */
/* 	} */
/* 	(void)py; */
/* 	(void)px; */
/* 	(void)line; */
/* 	(void)player; */
/* } */

void	renderPlayer(t_player *player)
{
	int	py;
	int	px;
	int	line;

	square(player->x + (g_width * player->y), 10, 0x0078FF);
	py = player->y;
	px = player->x;
	line = -1;
	while (++line < 30)
	{
		px =  cos(player->rotationAngle) * line + player->x;
		py =  sin(player->rotationAngle) * line + player->y;
		g_image_data[px + (g_width * py)] = 0x0078FF;
	}

}
 
