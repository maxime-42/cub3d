#include "cub3d.h"

/* int	keyPressed(int keyCode, t_player *player, t_info *info) */
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
		mlx_clear_window(g_info->mlx_ptr, g_info->win_mlx);
		mlx_destroy_window(g_info->mlx_ptr, g_info->win_mlx);
		exit(0);
	}
	if (keyCode == LEFT_ARROW || keyCode == RIGHT_ARROW)
	{
		printf("player->x == %d\n", player->x);
		printf("player->y == %d\n", player->y);
		player->rotationAngle += player->turnDirection * player->rotationSpeed;
		renderPlayer(&g_info->player, &g_info->pixel, (char **)g_info->map);			   player->turnDirection = 0;
	}
	/* (void)player; */
	(void)keyCode;
	(void)player;
	return (0);
}
	//renderPlayer(player, &info->pixel, (char **)info->map);
	//renderPlayer(player, &info->pixel, (char **)info->map);
