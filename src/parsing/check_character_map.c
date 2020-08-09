/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_character_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <mkayumba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:50:48 by user42            #+#    #+#             */
/*   Updated: 2020/08/09 15:53:14 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		check_first_character(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (!line[i] || line[i] != '1')
	{
		ft_putstr_fd("Error\nmap must begin with Wall\n", STDOUT);
		return (ERROR);
	}
	return (i);
}

static	int		check_last_character(char character)
{
	if (character != '1')
	{
		ft_putstr_fd("Error\nlast charecter of column must be wall\n", STDOUT);
		return (ERROR);
	}
	return (SUCCESS);
}

static int		is_valide_character(char *orientation, char character)
{
	char		*ptr;

	ptr = ft_strchr("012NSEW ", character);
	if (ptr)
	{
		if (ft_strchr("NSEW", character))
		{
			if (*orientation == '\0')
				*orientation = character;
			else
			{
				ft_putstr_fd("Error\nduplicate starting direction\n", STDOUT);
				return (ERROR);
			}
		}
	}
	else
	{
		ft_putstr_fd("Error\nunknown character\n", STDOUT);
		return (ERROR);
	}
	return (SUCCESS);
}

int				check_character_map(char *orientation)
{
	int			i;
	int			j;
	int			save;

	i = 1;
	save = 0;
	while (g_map[i + 1])
	{
		if ((j = check_first_character(g_map[i])) == ERROR)
			return (ERROR);
		while (g_map[i][++j])
		{
			if ((is_valide_character(orientation, g_map[i][j])) == ERROR)
				return (ERROR);
			if (check_character_around(g_map, i, j) == ERROR)
				return (ERROR);
			if (g_map[i][j] != ' ')
				save = j;
		}
		if (check_last_character(g_map[i][save]) == ERROR)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
