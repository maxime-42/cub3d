#include "../../include/cub3d.h"

static int	get_array(int nb_line, int nb_colonne)
{
	int	index_line;
	int	**array;

	index_line = -1;
	if (!(array = malloc(sizeof(int *) * (nb_line))))
		return (0);
	while (++index_line < nb_line)
	{
		if (!(array[index_line] = malloc(sizeof(int) * (nb_colonne))))
			return (0);
	}
	return (array);
}

static	void	copy_char_in_array(int *array, char *line)
{
	int	colone;
	int	index_line;

	colonne = -1;
	index_line = -1;
	while (line[++index_line])
	{
		if (!ft_strchr("012", line[index_line]))
			array[++colonne] = line[index_line] + 48;
		else if (!ft_strchr("NSEW", line[index_line]))
			 array[++colonne] = 42;
	}
	 array[++colonne] = -1;
}

int		put_map_in_array(t_info *info, t_list *begin, int colonne)
{
	int	**array;
	int	line;

	line = ft_lstsize(begin);
	info->line = line;
	if ((array = get_array(line, colonne)) == ERROR)
		return (ERROR);
	line = -1;
	while (begin)
	{
		++line;
		copy_char_in_array(array[line], begin->content);
		begin = begin->next;
	}
	info->map = array;
	return (SUCCESS);
}
