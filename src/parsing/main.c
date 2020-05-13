#include "cub3d.h"

int	parse_map(t_info *info)
{
	info->begin = 0;
	if (get_resolution(info) == ERROR)
		return (free_struct(info, ERROR));
	if (get_texture(info) == ERROR)
		return (free_struct(info, ERROR));
	if (get_sprint(info))
		return (free_struct(info, ERROR));
	if (get_color(info) == ERROR)
		return (free_struct(info, ERROR));
	if (put_map_in_list(&info->begin, info->fd) == ERROR)
		return (free_struct(info, ERROR));
	if (check_character_map(info->begin) == ERROR)
	{
		ft_lstclear(&info->begin, &free_list);
		return (free_struct(info, ERROR));
	}
	if (put_map_in_array(info, info->begin) == ERROR)
	{
		ft_lstclear(&info->begin, &free_list);
		return (free_struct(info, ERROR));
	}
	return (SUCCESS);
}
