#include "cub3d.h"


void	twoDMap_PlayerMovement(t_info *info)
{
	if (!(g_mlx_ptr = mlx_init()))
	{
		ft_putstr_fd("Error\nfaile init mlx\n", STDOUT);
		ft_lstclear(&info->begin, &free_list);
		exit(free_struct(info, ERROR));
	}
	if (!(g_win_mlx = mlx_new_window(g_mlx_ptr, g_width, g_height, "3D")))
	{
		ft_putstr_fd("Error\nfaile open window\n", STDOUT);
		exit(freeAll(ERROR));
	}
	info->player.x = g_width / 2;
	info->player.y = (g_width / 13);	
	info->player.turnDirection = 0;
	info->player.walkDirection = 0;
	info->player.rotationAngle = M_PI / 2;
	info->player.moveSpeed = 3.0;
	info->player.rotationSpeed = 3 * (M_PI / 180);
	if (createImg() == ERROR)
		exit(freeAll(ERROR));
	renderMap(info->map);
	renderPlayer(&info->player);
	mlx_put_image_to_window(g_mlx_ptr, g_win_mlx, g_img_ptr, 0, 0);	
}
