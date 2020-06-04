#include "cub3d.h"

int	get_file_descriptor(t_info *info, char *name_file)
{
	if ((info->fd = open(name_file, O_RDONLY)) < 0)
	{
		ft_putstr_fd("Error\n faillure open file\n", STDOUT);
		return (ERROR);
	}
	return (SUCCESS);
}
