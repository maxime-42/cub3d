#include "cub3d.h"

/* int	get_sprint(t_info *info) */
/* { */
/* 	info->sprint = 0; */
/* 	if (get_next_line(info->fd, &info->sprint) == ERROR) */
/* 		return (ERROR); */
/* 	free(info->sprint); */
/* 	if (get_next_line(info->fd, &info->sprint) == ERROR) */
/* 		return (ERROR); */
/* 	if ((ft_strncmp(info->sprint, "S ./", 3)) != 0) */
/* 	{ */
/* 		free(info->sprint); */
/* 		info->sprint = 0; */
/* 		ft_putstr_fd("Error\n worng sprint\n", STDOUT); */
/* 		return (ERROR); */
/* 	} */
/* 	return (SUCCESS); */
/* } */




int			get_path_sprite(int fd, t_sprite *sprite)
{
	char	*tmp;

	sprite->path = 0;
	if (get_next_line(fd, &sprite->path) == ERROR)
		return (ERROR);
	free(sprite->path);
	sprite->path = 0;
	if (get_next_line(fd, &sprite->path) == ERROR)
		return (ERROR);
	if ((ft_strncmp(sprite->path, "S ./", 3)) != 0)
	{
		free(sprite->path);
		sprite->path = 0;
		ft_putstr_fd("Error\n worng sprint\n", STDOUT);
		return (ERROR);
	}
	tmp = ft_strchr(sprite->path, '/');
	tmp = ft_strdup(tmp + 1);
	free(sprite->path);
	sprite->path = 0;
	sprite->path = tmp;
	return (SUCCESS);
}
