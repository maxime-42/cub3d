#include "../../include/cub3d.h"

static int	free_texture(char *texture[4])
{
	int	i;

	i = -1;
	ft_putstr_fd("Error\n faillur texture", STDOUT);
	while (texture[++i])
	{
		free(texture[i]);
		texture[i] = 0;
	}
	return (ERROR);
}

static	int	check_texture(char *texture[4], int line, char *direction)
{
	if ((ft_strncmp(texture[line], direction, 5)) != 0)
	{
		return (ERROR);
	}
	return (SUCCESS);
}

int		get_texture(t_info *info)
{
	int	count;

	count = -1;
	info->texture[0] = 0;
	info->texture[1] = 0;
	info->texture[2] = 0;
	info->texture[3] = 0;
	info->texture[4] = 0;
	while (++count <= 3)
	{
		if ((get_next_line(info->fd, &info->texture[count])) == ERROR)
			return (free_texture(info->texture));
	}
	if (check_texture(info->texture, 0, "NO ./") == ERROR)
		return (free_texture(info->texture));
	if (check_texture(info->texture, 1, "SO ./") == ERROR)
		return (free_texture(info->texture));
	if (check_texture(info->texture, 2, "WE ./") == ERROR)
		return (free_texture(info->texture));
	if (check_texture(info->texture, 3, "EA ./") == ERROR)
		return (free_texture(info->texture));
	return (SUCCESS);
}
