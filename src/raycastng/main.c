#include "cub3d.h"

static int	setup(t_info *info)
{
	if (open_window(info) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int		draw(t_info *info)
{
	if (setup(info) == ERROR)
	{
		return (ERROR);
	}
	renderMap(info, (char **)info->map);
	/* color_window(info); */
	return (SUCCESS);
}
