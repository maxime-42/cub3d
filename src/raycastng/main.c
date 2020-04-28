#include "cub3d.h"

/* static void	render(t_info *info) */
/* { */

/* } */

static int	setup(t_info *info)
{
	if ((info->mlx_ptr = mlx_init()) == NULL)
		return (ERROR);
	if (!(info->win_mlx = mlx_new_window(info->mlx_ptr, 640, 480, "Hello world")))
		return (ERROR);
	mlx_loop(info->mlx_ptr);
	(void)info;
	return (SUCCESS);
}

int		raycasting(t_info *info)
{
	if (setup(info) == ERROR)
	{
	  ft_putstr_fd("Error\nfaille minilibx", STDOUT);
		return (free_struct(info, ERROR));
	}
	return (SUCCESS);
}
