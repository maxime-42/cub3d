#include "../../include/cub3d.h"

static void	free_line(void *ptr)
{
	if (ptr)
		free((char *)ptr);
	ft_putstr_fd("Error\nfaillure map", STDOUT);
}

int	put_map_in_list(t_list **begin, int fd, int *max_column)
{
	int	return_gnl;
	t_list	*node;
	int	tmp_column;
	char	*line;

	*max_column = 0;
	return_gnl = get_next_line(fd, &line);
	free(line);
	while (return_gnl)
	{
		if ((return_gnl = get_next_line(fd, &line)) == ERROR)
		{
			ft_lstclear(begin, &free_line);
			return (ERROR);
		}
		if (!(node = ft_lstnew(line)))
		{
			ft_lstclear(begin, free_line);
			return (ERROR);
		}
		ft_lstadd_back(begin, node);
		tmp_column = (int)ft_strlen(line);
		if (tmp_column > *max_column)
			*max_column = tmp_column;
	}
	return (SUCCESS);
}
