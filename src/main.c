#include "cub3d.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	print_map(int **array, int line)
{
	int	i;
	int	j;

	i = -1;
	while (++i < line)
	{
		j = -1;
		while (array[i][++j] != -1)
			printf("%d", array[i][j]);
		printf("\n");
	}
}

static int	get_fd(t_info *info, char *name_file)
{
	if ((info->fd = open(name_file, O_RDONLY)) < 0)
	{
		ft_putstr_fd("Error\n faillure open file\n", STDOUT);
		return (ERROR);
	}
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_info	info;

	info.map = 0;
	if (ac != 2)
	{
		ft_putstr_fd("Error\n number argument\n", STDOUT);
		return (ERROR);
	}
	if (get_fd(&info, av[1]) == ERROR)
		return (ERROR);
	if (parse_map(&info) == ERROR)
		return (ERROR);
	if (raycasting(&info) == ERROR)
		return (free_struct(&info, ERROR));
	(void)ac;
	(void)av;
	free_struct(&info, SUCCESS);
	return (0);
}
