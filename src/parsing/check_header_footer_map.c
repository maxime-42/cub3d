#include "cub3d.h"

static int	check_header_map(t_list **begin, t_list *node)
{
	char	*line;
	t_list	*next;

	if (!node)
		return(ERROR);
	line = node->content;
	line += skip_space(line);
	if (!*line)
	{
		next = node->next;
		ft_list_remove_one_if(begin, node->content, &ft_strcmp, &freeContentNode);
		return (check_header_map(begin, next));
	}
	else if (*line != '1')
		return (ERROR);
	(void)begin;
	return (SUCCESS);
}

static int	check_footer_map(t_list **begin)
{
	char	*line;
	t_list	*node;

	node = ft_lstlast(*begin);
	if (!node)
		return (ERROR);
	line = node->content;
	line += skip_space(line);
	if (!*line || *line != '1')
	{
		return (ERROR);
	}
	(void)begin;
	return (SUCCESS);
}

int			check_header_footer(t_list **begin)
{
	if ((check_header_map(begin, *begin)) == ERROR)
	{
		ft_putstr_fd("Error\nthere is a problem with the format of the map\n", STDOUT);
		return (ERROR);
	}
	if (check_footer_map(begin) == ERROR)
	{
		ft_putstr_fd("Error\nthere is a problem with the format of the map\n", STDOUT);
		return (ERROR);
	}
	(void)begin;
	return (SUCCESS);
}
