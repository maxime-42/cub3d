#include "cub3d.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static int	setup(t_info *info)
{
	if (open_window(info) == ERROR)
		return (ERROR);
	info->player.turnDirection = 0;
	info->player.walkDirection = 0;
	info->player.radius = 10;
	info->player.rotationAngle = M_PI / 2;
	info->player.moveSpeed = 3.0;
	info->player.rotationSpeed = 3 * (M_PI / 180);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_info	info;
	int	keyCode;

	info.map = 0;
	if (ac != 2)
		return (write(1, "Error\nnumber argument\n", 24));
	if (get_fd(&info, av[1]) == ERROR)
		return (ERROR);
	if (parse_map(&info) == ERROR)
		return (ERROR);
	if (setup(&info) == ERROR)
	{
		ft_lstclear(&info.begin, &free_list);
		return (free_struct(&info, ERROR));
	}
	g_info = &info;
	/* renderMap((char **)info.map, &info.pixel); */
	/* mlx_key_hook(info.pixel.win_mlx, &keyPressed, &keyCode); */
	mlx_loop(info.mlx_ptr);
	return (0);
}
