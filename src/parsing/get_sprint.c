#include "../../include/cub3d.h"

int	get_sprint(t_info *info)
{
	info->sprint = 0;
	if (get_next_line(info->fd, &info->sprint) == ERROR)
		return (ERROR);
	free(info->sprint);
	if (get_next_line(info->fd, &info->sprint) == ERROR)
		return (ERROR);
	if ((ft_strncmp(info->sprint, "S ./", 3)) != 0)
	{
		free(info->sprint);
		info->sprint = 0;
		ft_putstr_fd("Error\n worng sprint\n", STDOUT);
		return (ERROR);
	}
	return (SUCCESS);
}
