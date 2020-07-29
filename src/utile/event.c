#include "cub3d.h"

int	keyPressed(int keyCode)
{
	if (keyCode == UP_ARROW)
		g_player.walkDirection = +1;
	else if (keyCode == DOWN_ARROW)
        g_player.walkDirection = -1;
	else if (keyCode == RIGHT_ARROW)
        g_player.turnDirection = +1;
	else if (keyCode == LEFT_ARROW)
		g_player.turnDirection = -1;
	else if (keyCode == QUIT)
		exit(freeAll(SUCCESS));
	else if (keyCode == TRANSLATION_RIGHT)
	{
		g_player.translation = 1;
		g_player.walkDirection = +1;
	}
	else if (keyCode == TRANSLATION_LEFT)
	{
		g_player.translation = -1;
		g_player.walkDirection = -1;
	}
	return (0);
}

int	keyRelease(int keyCode)
{
    if (keyCode == UP_ARROW)
		g_player.walkDirection = 0;
	else if (keyCode == DOWN_ARROW)
		g_player.walkDirection = 0;
	else if (keyCode == RIGHT_ARROW)
		g_player.turnDirection = 0;
	else if (keyCode == LEFT_ARROW)
		g_player.turnDirection = 0;
	else if (keyCode == TRANSLATION_RIGHT || keyCode == TRANSLATION_LEFT)
	{
		g_player.translation = 0;
		g_player.walkDirection = 0;
	}
	return (0);
}

int	close_window(int keycode)
{
	exit(freeAll(SUCCESS));
	(void)keycode;
}

void	handling_event(t_info *info)
{
	int	keyCode;

	keyCode = 0;
	mlx_hook(g_win_mlx, 17, 1L << 17, &close_window, &keyCode);
	mlx_hook(g_win_mlx, 2, (1L << 0), &keyPressed, &keyCode);
	mlx_hook(g_win_mlx, 3, (1L << 1), &keyRelease, &keyCode);
	mlx_loop_hook(g_mlx_ptr, &game_loop, &info);
	mlx_loop(g_mlx_ptr);
}
