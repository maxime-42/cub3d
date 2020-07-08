#include "cub3d.h"

void	print_list(t_list *tmp)
{
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
}

int	parsing_map(t_info *info)
{
	info->begin = 0;
	if (get_Screen_Size(info) == ERROR)
		return (free_struct(info, ERROR));
	if (checkTexture(info->fd, g_texture) == ERROR)
		return (free_struct(info, ERROR));
	if (get_path_sprite(info->fd, &g_sprite))
		return (free_struct(info, ERROR));
	if (get_color(info) == ERROR)
		return (free_struct(info, ERROR));
	if (put_map_in_list(&info->begin, info->fd) == ERROR)
		return (free_struct(info, ERROR));
	if (check_character_map(info->begin) == ERROR)
		return(freeAll(ERROR));
	if (put_map_in_array(info, info->begin) == ERROR)
		return(freeAll(ERROR));
	if (put_the_same_number_of_column(info->begin) == ERROR)
		return(freeAll(ERROR));
	if (!g_info->orientation)
	{
		ft_putstr_fd("Error\nThere is not an orientation character\n", STDOUT);
		return(freeAll(ERROR));
	}
	return (SUCCESS);
}
