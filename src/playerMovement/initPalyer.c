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
	g_player.moveSpeed = 2;
	g_player.rotationSpeed = 0.2 * (M_PI / 180);
}

/* void	playerMovement(t_info *info) */
/* { */
/* 	if (!(g_mlx_ptr = mlx_init())) */
/* 	{ */
/* 		ft_putstr_fd("Error\nfaile init mlx\n", STDOUT); */
/* 		ft_lstclear(&info->begin, &free_list); */
/* 		exit(free_struct(info, ERROR)); */
/* 	} */
/* 	if (!(g_win_mlx = mlx_new_window(g_mlx_ptr, g_width, g_height, "3D"))) */
/* 	{ */
/* 		ft_putstr_fd("Error\nfaile open window\n", STDOUT); */
/* 		exit(freeAll(ERROR)); */
/* 	} */
/* 	g_window_width = (int)ft_strlen(info->begin->content) * TILE_SIZE; */
/* 	g_window_height = info->height * TILE_SIZE; */
/* 	info->player.x = g_window_width - (g_window_width / 3) ;    //position player en x */
/* 	info->player.y = (g_width / 13); //position player en y */
/* 	info->player.radius = 5; */
/* 	info->player.turnDirection = 0; */
/* 	info->player.walkDirection = 0; */
/* 	info->player.rotationAngle = M_PI / 2; */
/* 	info->player.moveSpeed = 3.0; */
/* 	info->player.rotationSpeed = 3 * (M_PI / 180); */
/* 	drawMap(info->map); */
/* 	drawPlayer(&info->player); */
/* } */
