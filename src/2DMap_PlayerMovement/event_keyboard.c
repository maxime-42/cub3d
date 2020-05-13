#include "cub3d.h"

/* static void	playerMove(int keyCode) */
/* { */
/* 	t_player *player; */
/* 	double moveStep; */
/* 	int	test; */
/* 	test = 0; */
/* 	if (keyCode == LEFT_ARROW || keyCode == RIGHT_ARROW) */
/* 	{ */
/* 		test++; */
/* 		/\* printf("left or right\n");		 *\/ */
/* 		player->rotationAngle += player->turnDirection * player->rotationSpeed; */
/* 		player->turnDirection = 0; */
/* 	} */
/* 	else if (keyCode == UP_ARROW || keyCode == DOW_ARROW) */
/* 	{ */
/* 		test++; */
/* 		/\* printf("top or down\n"); *\/ */
/* 		moveStep = player->walkDirection * player->moveSpeed; */
/* 		player->x += cos(player->rotationAngle) * moveStep; */
/* 		player->y += sin(player->rotationAngle) * moveStep; */
/* 	} */
/* 	if (test) */
/* 	{ */
/* 		printf("hellow\n"); */
/* 		renderMap(g_info->map); */
/* 		renderPlayer(&g_info->player); */
/* 		mlx_put_image_to_window(g_mlx_ptr, g_win_mlx, g_img_ptr, 0, 0); */
/* 	} */
/* 	(void)keyCode; */
/* 	(void)test;	 */
/* } */

int	keyPressed(int keyCode)
{
	t_player *player;

	player = &g_info->player;
	if (keyCode == UP_ARROW)
		player->walkDirection += 1;
	else if (keyCode == DOW_ARROW)
		player->walkDirection -= 1;
	else if (keyCode == LEFT_ARROW)
		player->turnDirection -= 1;
	else if (keyCode == RIGHT_ARROW)
		player->turnDirection += 1;
	else if (keyCode == QUIT)
	{
		mlx_clear_window(g_mlx_ptr, g_win_mlx);
		mlx_destroy_window(g_mlx_ptr, g_win_mlx);
		ft_lstclear(&g_info->begin, &free_list);
		free_struct(g_info, ERROR);
		exit(SUCCESS);
	}
	/* playerMove(keyCode); */
	(void)keyCode;
	(void)player;
	return (0);
}


/* int				keyRelease(int keyCode) */
/* { */
/* 	t_player	*player; */
/* 	player = &g_info->player;	 */
/* 	if (keyCode == LEFT_ARROW || keyCode == RIGHT_ARROW) */
/* 	{ */
/* 		/\* player->rotationAngle += player->turnDirection * player->rotationSpeed; *\/ */
/* 		player->turnDirection = 0; */
/* 	} */
/* 	else if (keyCode == UP_ARROW || keyCode == DOW_ARROW) */
/* 	{ */
/* 		/\* test++; *\/ */
/* 		/\* moveStep = player->walkDirection * player->moveSpeed; *\/ */
/* 		/\* player->x += cos(player->rotationAngle) * moveStep; *\/ */
/* 		/\* player->y += sin(player->rotationAngle) * moveStep; *\/ */
/* 		player->walkDirection = 0; */
/* 	}  */
/* 	/\* if (test) *\/ */
/* 	/\* { *\/ */
/* 	/\* 	renderMap(g_info->map); *\/ */
/* 	/\* 	renderPlayer(&g_info->player); *\/ */
/* 	/\* 	mlx_put_image_to_window(g_mlx_ptr, g_win_mlx, g_img_ptr, 0, 0); *\/ */
/* 	/\* } *\/ */
/* 	(void)keyCode; */
/* 	return (0); */
/* } */


int	keyRelease(int keyCode)
{
	t_player *player;
	double moveStep;
	int		test;

	test = 0;
	player = &g_info->player;
	if (keyCode == LEFT_ARROW || keyCode == RIGHT_ARROW)
	{
		test++;
		player->rotationAngle += player->turnDirection * player->rotationSpeed;
		player->turnDirection = 0;
	}
	else if (keyCode == UP_ARROW || keyCode == DOW_ARROW)
	{
		test++;
		moveStep = player->walkDirection * player->moveSpeed;
		player->x += cos(player->rotationAngle) * moveStep;
		player->y += sin(player->rotationAngle) * moveStep;
		player->walkDirection = 0;
	}
	if (test)
	{
		renderMap(g_info->map);
		renderPlayer(&g_info->player);
		mlx_put_image_to_window(g_mlx_ptr, g_win_mlx, g_img_ptr, 0, 0);
	}
	return (0);
}
