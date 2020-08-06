/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 12:06:33 by lenox             #+#    #+#             */
/*   Updated: 2020/08/06 13:08:38 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_pressed(int key_code)
{
	if (key_code == UP_ARROW)
		g_player.walkDirection = +1;
	else if (key_code == DOWN_ARROW)
		g_player.walkDirection = -1;
	else if (key_code == RIGHT_ARROW)
		g_player.turnDirection = +1;
	else if (key_code == LEFT_ARROW)
		g_player.turnDirection = -1;
	else if (key_code == QUIT)
		exit(free_all(SUCCESS));
	else if (key_code == TRANSLATION_RIGHT)
	{
		g_player.translation = 1;
		g_player.walkDirection = +1;
	}
	else if (key_code == TRANSLATION_LEFT)
	{
		g_player.translation = -1;
		g_player.walkDirection = -1;
	}
	return (0);
}

int		key_release(int key_code)
{
	if (key_code == UP_ARROW)
		g_player.walkDirection = 0;
	else if (key_code == DOWN_ARROW)
		g_player.walkDirection = 0;
	else if (key_code == RIGHT_ARROW)
		g_player.turnDirection = 0;
	else if (key_code == LEFT_ARROW)
		g_player.turnDirection = 0;
	else if (key_code == TRANSLATION_RIGHT || key_code == TRANSLATION_LEFT)
	{
		g_player.translation = 0;
		g_player.walkDirection = 0;
	}
	return (0);
}

int		close_window(int keycode)
{
	exit(free_all(SUCCESS));
	(void)keycode;
}

void	handling_event(t_info *info)
{
	int	key_code;

	key_code = 0;
	mlx_hook(g_win_mlx, 17, 1L << 17, &close_window, &key_code);
	mlx_hook(g_win_mlx, 2, (1L << 0), &key_pressed, &key_code);
	mlx_hook(g_win_mlx, 3, (1L << 1), &key_release, &key_code);
	mlx_loop_hook(g_mlx_ptr, &game_loop, &info);
	mlx_loop(g_mlx_ptr);
}
