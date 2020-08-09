/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 11:56:59 by lenox             #+#    #+#             */
/*   Updated: 2020/08/09 14:36:14 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			nb_line_and_nb_column(t_info *info)
{
	if ((info->height = ft_lstsize(info->begin)) < 3)
	{
		ft_putstr_fd("Error\nthere are not enought number line\n", STDOUT);
		return (ERROR);
	}
	if ((info->column = nb_cloumn(info->begin)) < 3)
	{
		ft_putstr_fd("Error\nthere are not enought number column\n", STDOUT);
		return (ERROR);
	}
	return (SUCCESS);
}


int			check_that_line_is_wall(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == ' ')
			;
		else if (line[i] != '1')
		{
			ft_putstr_fd("Error\nthe map maybe not cover by walls\n", STDOUT);
			return (ERROR);
		}
	}
	return (SUCCESS);
}


static int	header_empty_line_map(t_list **begin, t_list *node)
{
	char	*line;
	t_list	*next;

	if (!node)
		return (ERROR);
	line = node->content;
	line += skip_space(line);
	if (!*line)
	{
		next = node->next;
		ft_list_remove_one_if(begin, node->content,
		&ft_strcmp, &free_content_node);
		return (header_empty_line_map(begin, next));
	}
	else if (*line != '1')
		return (ERROR);
	(void)begin;
	return (SUCCESS);
}

static int	footer_empty_line_map(t_list **begin)
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

int			delete_empty_line_map(t_list **begin)
{
	if ((header_empty_line_map(begin, *begin)) == ERROR)
	{
		ft_putstr_fd("Error\nheader map there is a problem with ", STDOUT);
		ft_putstr_fd("the format of the map\n", STDOUT);
		return (ERROR);
	}
	if (footer_empty_line_map(begin) == ERROR)
	{
		ft_putstr_fd("Error\nfooter map there is a problem with ", STDOUT);
		ft_putstr_fd("the format of the map\n", STDOUT);
		return (ERROR);
	}
	(void)begin;
	return (SUCCESS);
}
