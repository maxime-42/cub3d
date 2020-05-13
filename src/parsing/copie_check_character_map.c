#include "cub3d.h"

static int	last_char(char **befor_line, char *current_line, int *stock_index)
{
	int	befor;
	int	current;

	current = stock_index[0];
	befor = stock_index[2];
	if (!*current_line)
		return (ERROR);
	if (current_line[current] != WALL)
		return (ERROR);
	if (befor > current)
	{
		if (befor_line[0][current] != WALL)
			return (ERROR);
	}
	else if (current > befor)
	{
		if (current_line[befor] != WALL)
			return (ERROR);
	}
	befor_line[0] = current_line;
	stock_index[2] = current;
	return (SUCCESS);
}

static int	is_valide_char(char *current_line, int *stock_index)
{
	int	index_current;
	static	int direction = 0;

	index_current = stock_index[0];
	while (ft_isspace(current_line[index_current]))
		index_current++;
	if (!stock_index[0] && current_line[index_current] != WALL)
		return (ERROR);
	if (ft_strchr("012 ", current_line[index_current]))
		;
	else if (ft_strchr("NSEW", current_line[index_current]))
	{
		if (!direction)
			direction = 1;
		else
			return (ERROR);
	}
	else
		return (ERROR);
	stock_index[0] = index_current;
	if (current_line[index_current] != '\0')
		stock_index[1] = index_current;
	else if (current_line[index_current] == '\0')
		stock_index[0] -= 1;
	return (SUCCESS);
}

static int	first_line(char *current_line, char **befor_line, int *index_befor)
{

	int	index_current;

	*index_befor = 0;
	index_current = 0;
	while (ft_isspace(current_line[index_current]))
		index_current += 1;
	if (current_line[index_current] != WALL)
		return (ERROR);
	while (current_line[index_current])
	{
		if (current_line[index_current] != WALL)
			return (ERROR);
		else
			*index_befor = index_current;
		index_current += 1;
	}
	while (ft_isspace(current_line[index_current]))
		index_current += 1;
	if (current_line[index_current] != '\0')
		return (ERROR);
	befor_line[0] = current_line;
	(void)index_current;
	return (SUCCESS);
}

static int	last_line(char *befor_line, char *current_line, int *stock_index)
{
	int	index_current;

	index_current = 0;
	while (ft_isspace(current_line[index_current]))
		index_current += 1;
	if (current_line[index_current] != WALL)
		return (ERROR);
	while (current_line[index_current])
	{
		if (!ft_strchr("1 ", current_line[index_current]))
			return (ERROR);
		if (current_line[index_current] == WALL)
			stock_index[1] = index_current;
		index_current++;
	}
	if (last_char(&befor_line, current_line, stock_index) == ERROR)
		return (ERROR);
	(void)befor_line;
	return (SUCCESS);
}

int		check_character_map(t_list *begin)
{
	char	*current_line;
	char	*befor_line;
	int	stock_index[3];

	current_line = 0;
	befor_line = 0;
	stock_index[0] = 0;
	if (first_line(begin->content, &befor_line, &stock_index[2]) == ERROR)
		return (ERROR);
	while ((begin = begin->next))
	{
		stock_index[0] = -1;
		current_line = (char *)begin->content;
		while (current_line[++stock_index[0]])
		{
			if (is_valide_char(current_line, stock_index) == ERROR)
				return (ERROR);
		}
		stock_index[0] -= 1;
		if (last_char(&befor_line, current_line, stock_index) == ERROR)
			return (ERROR);
	}
	if (last_line(befor_line, current_line, stock_index) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
