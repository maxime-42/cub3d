#include "../../include/cub3d.h"

int	parse_map(t_info *info)
{
	t_list	*begin;

	begin = 0;
	if (get_resolution(info) == ERROR)
		return (free_struct(info, ERROR));
	if (get_texture(info) == ERROR)
		return (free_struct(info, ERROR));
	if (get_sprint(info))
		return (free_struct(info, ERROR));
	if (get_color(info) == ERROR)
		return (free_struct(info, ERROR));
	if (put_map_in_list(&begin, info->fd, &info->max_colunn) == ERROR)
		return (free_struct(info, ERROR));
	if (check_character_map(begin) != ERROR)
	{
		if (put_map_in_array(info, begin, info->max_colunn) == ERROR)
		{
			ft_lstclear(&begin, &free_list);
			return (free_struct(info, ERROR));
		}
	}
	else
		ft_putstr_fd("Error\nBad a character in map\n", STDOUT);
	ft_lstclear(&begin, &free_list);
	return (SUCCESS);
}
