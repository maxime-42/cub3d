#include "cub3d.h"


static char	*get_value_color(int *ptr, char *line, int column)
{
	if (*line != ' ' && column == 0)
	{
		ft_putstr_fd("Error\n first character must be spaces\n", STDOUT);
		return (0);
	}  
	if (!*line)
	{
		ft_putstr_fd("Error\nwrong format for color\n", STDOUT);
		return (0);
	}
	line += skip_space(line);
	if (ft_isdigit(*line))
		*ptr = atoi(line);
	else
	{
		ft_putstr_fd("Error\nwrong character for color\n", STDOUT);
		return (0);
	}
	line += skip_number(line);
	line += skip_space(line);	
	if (column < 2 && *line == ',')
		line += 1;
	else
	{
		line += skip_space(line);
		if (*line)
		{
		    ft_putstr_fd("Error\nwrong character", STDOUT);
			return (0);
		}
	}
	return (line);
}

int		get_color(t_list **begin, int *color_ceiling)
{
	char	*line;
	t_list	*node;
	int	array_color[3];
	
	if (!(node = get_node(begin, "F")))
		return (ERROR);
	line = node->content;
	line += skip_space(line);
	line += 1;
	if (!(line = get_value_color(&array_color[0], line, 0)))
  		return (ERROR);
	if (!(line = get_value_color(&array_color[1], line, 1)))
  		return (ERROR);
	if (!(line = get_value_color(&array_color[2], line, 2)))
  		return (ERROR);
	printf("%d | %d | %d\n", array_color[0], array_color[1], array_color[2]);
	(void)color_ceiling;
	return (SUCCESS);
}
