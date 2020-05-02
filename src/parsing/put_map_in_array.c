#include "cub3d.h"

int		put_map_in_array(t_info *info, t_list *begin)
{
	char	**array;
	int	line;

	if ((info->height = ft_lstsize(begin)) < 3)
	{
		ft_putstr_fd("Error\nthere is not enough line\n", STDOUT);
		return (ERROR);
	}
	if (!(array = malloc(sizeof(char *) * (info->height + 1))))
	{
		ft_putstr_fd("Error\nMalloc failure\n", STDOUT);
		return (ERROR);
	}
	line = -1;
	info->column = 0;
	while (begin)
	{
		array[++line] = (char *)begin->content;
		if ((int)ft_strlen((char *)begin->content) > info->column)
			info->column = (int)ft_strlen((char *)begin->content);
		begin = begin->next;
	}
	array[++line] = 0;
	info->map = array;
	return (SUCCESS);
}
