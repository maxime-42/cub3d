/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <mkayumba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:14:55 by user42            #+#    #+#             */
/*   Updated: 2020/08/06 12:42:45 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_width(char *line, int *screen_width)
{
	int	size_width;

	line += skip_space(line);
	if (*line == 'R')
		line++;
	if (!ft_isspace(*line))
	{
		ft_putstr_fd("Error\nwindow size the", STDOUT);
		ft_putstr_fd("first character must be spaces\n", STDOUT);
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
		ft_putstr_fd("Error\nwindow wrong format for size window\n", STDOUT);
		return (0);
	}
	*screen_width = size_width;
	return (line);
}

char	*get_height(char *line, int *screen_height)
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
	*screen_height = size_height;
	return (line);
}

int		get_window_size(t_list **begin)
{
	char	*line;
	t_list	*node;

	if (!(node = get_node(begin, "R ", 2)))
	{
		ft_putstr_fd("Error\n", STDOUT);
		ft_putstr_fd("not find resolution or format is wrong\n", STDOUT);
		return (ERROR);
	}
	line = node->content;
	if (!(line = get_width(line, &g_screen_width)))
		return (ERROR);
	if (!(line = get_height(line, &g_screen_height)))
		return (ERROR);
	if (g_screen_width < 100 || g_screen_height < 100)
	{
		ft_putstr_fd("Error\n", STDOUT);
		ft_putstr_fd("window size not correct\n", STDOUT);
		return (ERROR);
	}
	ft_list_remove_one_if(begin, node->content, &ft_strcmp, &free_content_node);
	return (SUCCESS);
}
