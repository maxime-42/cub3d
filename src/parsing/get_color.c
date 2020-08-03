#include "cub3d.h"

static char *utile_get_value_color(char *line, int column)
{
	line += skip_number(line);
	line += skip_space(line);
	if (column < 2 && *line == ',')
		line += 1;
	else
	{
		line += skip_space(line);
		if (*line)
		{
		    ft_putstr_fd("Error\nwrong character for", STDOUT);
			return (0);
		}
	}
	return (line);
}

static char	*get_value_color(int *ptr, char *line, int column)
{

	if (!*line)
	{
		ft_putstr_fd("Error\nwrong format for color\n", STDOUT);
		return (0);
	}
	line += skip_space(line);
	if (ft_isdigit(*line))
	{
		*ptr = atoi(line);
		if ((*ptr & 255) != *ptr)
		{
			ft_putstr_fd("Error\nthe color number must be less than 255\n", STDOUT);
			return (0);
		}
	}
	else
	{
		ft_putstr_fd("Error\nnwrong character for color\n", STDOUT);
		return (0);
	}
	return ((line = utile_get_value_color(line, column)));
}

int			get_color(t_list **begin, char *name, int *num_color)
{
	char	*line;
	t_list	*node;
	int		array_color[3];

	if (!(node = get_node(begin, name, 2)))
	{
		ft_putstr_fd("Error\nnot find color or format is wrong\n", STDOUT);
		return (ERROR);
	}
	line = node->content;
	line += 1;
	if (*line != ' ')
	{
		ft_putstr_fd("Error\ncolor first character must be spaces\n", STDOUT);
		return (ERROR);
	}
	if (!(line = get_value_color(&array_color[0], line, 0)))
		return (ERROR);
	if (!(line = get_value_color(&array_color[1], line, 1)))
  		return (ERROR);
	if (!(line = get_value_color(&array_color[2], line, 2)))
		return (ERROR);
	*num_color = 0;
	*num_color = (((array_color[0]) << 16) + ((array_color[1]) << 8) + (array_color[2]));
	/* printf("%d | %d | %d |\n", array_color[0], array_color[1], array_color[2]); */
	ft_list_remove_one_if(begin, node->content, &ft_strcmp, &freeContentNode);
	return (SUCCESS);
}
