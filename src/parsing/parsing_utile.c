#include "cub3d.h"

void	print_list(t_list *tmp)
{
	while (tmp)
	{
		/* printf("%s\n", (char *)tmp->content); */
		/* printf("strlen = %d\n", (int)ft_strlen((char *)tmp->content)); */
		tmp = tmp->next;
	}
}

int	skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	return (i);
}

int	skip_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (i);
}

t_list	*get_node( t_list **begin, char *search, int n)
{
	t_list	*node;

	node = ft_list_find(*begin, search, n, &ft_memcmp);
	if (!node)
	{
		return (0);
	}
	if (node == ft_lstlast(*begin))
	{
		/* ft_putstr_fd("Error\nnothing else must be at the end except wall map\n", STDOUT); */
		return (0);
	}
	return (node);
}

int			nb_cloumn(t_list *node)
{
	int		size;
	int		new_size;

	size = 0;
	while (node)
	{
		new_size = (int)ft_strlen(node->content);
		if (new_size > size)
			size = new_size;
		node = node->next;
	}
	return (size);
}

int	isValideCharacter(char *orientation, char character)
{
	char	*ptr;

	ptr = ft_strchr("012NSEW ", character);
	if (ptr)
	{
		if (ft_strchr("NSEW", character))
		{
			if (*orientation == '\0')
				*orientation = character;
			else
			{
				ft_putstr_fd("Error\nto many direction\n", STDOUT);
				return (ERROR);
			}
		}
	}
	else
	{
		ft_putstr_fd("Error\nunknown character ", STDOUT);
		return(ERROR);
	}
	return (SUCCESS);
}

int	check_around_character(char **map, int i, int j)
{
	int	ret;

	ret = 0;
	if (ft_strchr("012NSEW", map[i][j]))
	{
		if (map[i][j] == ' ')
		{
			if (map[i][j + 1] == ' ')
				ret++;
			if (map[i][j - 1] == ' ')
				ret++;
			if (map[i + 1][j] == ' ')
				ret++;
			if (map[i - 1] [j] == ' ')
				ret++;
		}
	}
	return (ret == 4 ? ERROR : SUCCESS);
}
