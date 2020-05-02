#include "cub3d.h"

int	open_window(t_info *info)
{
	int	width;
	int	height;
	void	*win_mlx;

	width = info->window_width;
	height = info->window_width;
	if (!(info->mlx_ptr = mlx_init()))
	{
		ft_putstr_fd("Error\nfaile connexion to minilibx", STDOUT);
		return (ERROR);
	}
	if (!(win_mlx = mlx_new_window(info->mlx_ptr, height, width, "Hello")))
	{
		ft_putstr_fd("Error\nfaile open window", STDOUT);
		return (ERROR);
	}
	info->win_mlx = win_mlx;
	(void)info;
	return (SUCCESS);
}

void	color_window(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->window_height)
	{
		j = -1;
		while (++j < info->window_width)
		{
			mlx_pixel_put(info->mlx_ptr, info->win_mlx, j, i, 16722944);
		}
	}
}
