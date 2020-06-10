#include "cub3d.h"

static int			get_the_largest_column(t_list *begin)
{
	t_list			*tmp;
	int				largest_column;
	int				nb_column;

	largest_column = 0;
	tmp = begin;
	while (tmp)
	{
		nb_column = (int)ft_strlen(tmp->content);
		if (nb_column > largest_column)
			largest_column = nb_column;
		tmp = tmp->next;
	}
	return (largest_column);
}

static	void		fill_str(char *str, int nb_char)
{
	int				n;

	n = -1;
	while (++n < nb_char)
	{
		str[n] = '1';
	}
	str[n] = '\0';
}

int					put_the_same_number_of_column(t_list *begin)
{
	t_list			*tmp;
	int				nb_char;
	char			*str;
	int				largest_column;

	tmp = begin;
	largest_column = get_the_largest_column(begin);
	while (tmp)
	{
		if (largest_column != (int)ft_strlen(tmp->content))
		{
			if (!(str = malloc(sizeof(char) * (largest_column + 1))))
			{
				ft_putstr_fd("Error\nmalloc failed\n", STDOUT);
				return (ERROR);
			}
			nb_char = ft_strlen(tmp->content);
			str = (char *)ft_memmove(str, tmp->content, (size_t)nb_char);
			fill_str(str + nb_char, largest_column - nb_char);
			free((char*)tmp->content);
			tmp->content = str;
		}
		tmp = tmp->next;
	}
	return (SUCCESS);
}
