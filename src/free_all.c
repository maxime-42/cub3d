#include "../include/cub3d.h"

int		free_struct(t_info *info, int code_return)
{
	if (info->map)
	{
		free(info->map);
		info->map = 0;
	}
	if (info->texture[0])
		free(info->texture[0]);
	if (info->texture[1])
		free(info->texture[1]);
	if (info->texture[2])
		free(info->texture[2]);
	if (info->texture[3])
		free(info->texture[3]);
	if (info->sprint)
		free(info->sprint);
	return (code_return);
}

void		free_list(void *line)
{
	if ((char *)line)
	{
		free((char *)line);
		line = 0;
	}
}
