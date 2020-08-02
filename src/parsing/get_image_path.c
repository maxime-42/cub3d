#include "cub3d.h"

static int	check_xpm_extension(char *line)
{
	int		end;

	end = ft_strlen(line) - 1;
	while (end && ft_isspace(line[end]))
			line[end--] = '\0';
	end -= 3;
	if (end > 4)
	{
		if (ft_strcmp(line + end, ".xpm"))
		{
			ft_putstr_fd("Error\nit is not xpm extension\n", STDOUT);
			return (ERROR);
		}
	}
	else
	{
		ft_putstr_fd("Error\nthe are trouble with name file\n", STDOUT);
		return (ERROR);
	}
	return (SUCCESS);
}

int			get_image_path(t_list **begin, char *name, int n, char **dest)
{
	t_list	*node;
	char	*line;

	if (!(node = get_node(begin, name, n)))
	{
			ft_putstr_fd("Error\nit is not possible to load image\n", STDOUT);
			return (ERROR);
	}
	line = (char *)node->content;
	line += 2;
	line += skip_space(line);
	if (check_xpm_extension(line) == ERROR)
		return (ERROR);
	dest[0] = ft_strdup(line);
	ft_list_remove_one_if(begin, node->content, &ft_strcmp, &freeContentNode);
	(void)dest;
	return (SUCCESS);
}
