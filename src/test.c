#include "cub3d.h"

int	test()
{
	int     bpp;
	int     size_line;
	int     endian;
	int	color = 4325631;
g_info->img_ptr = mlx_new_image(g_info->mlx_ptr, info->window_heightt, info->window_height);
g_info->img_data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
mlx_put_image_to_window(g_info->mlx_ptr, info->win_ptr, info->img_ptr, 0, 0);
mlx_get_color_value (g_info->mlx_ptr, color);
 return (0);
}
