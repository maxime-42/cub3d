#include "cub3d.h"

char	*get_width(char *line)
{
	int	size_width;

	line += skip_space(line);
	if (*line == 'R')
		line++;
	if (!ft_isspace(*line))
	{
		ft_putstr_fd("Error\nwrong format for size window\n", STDOUT);
		return (0);
	}
	line += skip_space(line);
	if (ft_isdigit(*line))
	{
		size_width = atoi(line);
		line += skip_number(line);
	}
	else
	{
		printf("hellow");
		ft_putstr_fd("Error\nwrong format for size window\n", STDOUT);
		return (0);
	}
	g_screen_width = size_width;
	return (line);
}

char	*get_height(char *line)
{
	int	size_height;

	line += skip_space(line);
	if (ft_isdigit(*line))
	{
		size_height = atoi(line);
		line += skip_number(line);
	}
	else
	{
		ft_putstr_fd("Error\nwrong format for size window\n", STDOUT);
		return (0);
	}
	line += skip_space(line);
	if (*line)
	{
		ft_putstr_fd("Error\nwrong character for size window\n", STDOUT);
		return (0);
	}
	g_screen_height = size_height;
	return (line);
}


int	get_window_size(t_list **begin)
{
	char	*line;
	t_list	*node;

	if (!(node = get_node(begin, "R")))
	{
		ft_putstr_fd("not find resolution\n", STDOUT);	  
		return (ERROR);
	}
	line = node->content;
	if (!(line = get_width(line)))
		return (ERROR);
	if (!(line = get_height(line)))
		return (ERROR);
	ft_list_remove_one_if(begin, node->content, &ft_strcmp, &freeContentNode);
	return (SUCCESS);
}
