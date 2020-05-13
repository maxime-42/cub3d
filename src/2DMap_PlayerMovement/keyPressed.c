#include "cub3d.h"

int	keyPressed(int keyCode)
{
	t_player *player;

	player = &g_info->player;
	if (keyCode == UP_ARROW)
	{
		player->walkDirection += 1;
		printf("Key up\n");
	}
	else if (keyCode == DOW_ARROW)
	{
		player->walkDirection -= 1;
		printf("Key Down\n");
	}
	else if (keyCode == LEFT_ARROW)
	{
		player->turnDirection -= 1;
		printf("Left\n");
	}
	else if (keyCode == RIGHT_ARROW)
	{
		player->turnDirection += 1;
		printf("Right\n");
	}
	else if (keyCode == QUIT)
	{
		mlx_clear_window(g_mlx_ptr, g_win_mlx);
		mlx_destroy_window(g_mlx_ptr, g_win_mlx);
		ft_lstclear(&g_info->begin, &free_list);
		free_struct(g_info, ERROR);
		exit(0);
	}
	(void)keyCode;
	(void)player;
	return (0);
}

int	keyRelease(int keyCode)
{
	t_player *player;

	player = &g_info->player;	
	if (keyCode == LEFT_ARROW || keyCode == RIGHT_ARROW)
	{
		player->rotationAngle += player->turnDirection * player->rotationSpeed;		
		player->turnDirection = 0;
		mlx_destroy_image(g_mlx_ptr, g_img_ptr);		
		createImg();
	}
	return (0);
}
