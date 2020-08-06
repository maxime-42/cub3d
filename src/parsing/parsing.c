/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <mkayumba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:52:27 by user42            #+#    #+#             */
/*   Updated: 2020/08/06 13:06:43 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	put_map_in_array(t_list *node, int nb_line, int nb_column)
{
	int		i;

	i = -1;
	g_map = array_char(nb_line, nb_column);
	if (!g_map)
	{
		ft_putstr_fd("Error\nmalloc failure\n", STDOUT);
		return (ERROR);
	}
	while (++i < nb_line)
	{
		g_map[i] = ft_strcpy(g_map[i], node->content);
		node = node->next;
	}
	return (SUCCESS);
}

static	int	put_files_in_list(t_list **begin, int fd)
{
	char	*line;
	t_list	*node;
	int		return_gnl;

	return_gnl = 1;
	while (return_gnl)
	{
		if ((return_gnl = get_next_line(fd, &line)) == ERROR)
		{
			ft_putstr_fd("Error\nread failed\n", STDOUT);
			return (ERROR);
		}
		if (!(node = ft_lstnew(line)))
		{
			ft_putstr_fd("Error\nmalloc failed for create node\n", STDOUT);
			return (ERROR);
		}
		ft_lstadd_back(begin, node);
	}
	if (close(fd) != SUCCESS)
	{
		ft_putstr_fd("Error\nclose file\n", STDOUT);
		return (ERROR);
	}
	return (SUCCESS);
}

static int	check_and_get_info(t_info *info)
{
	info->color_floor = 0;
	info->color_ceiling = 0;
	if (get_window_size(&info->begin) == ERROR)
		return (free_all(ERROR));
	if (get_color(&info->begin, "C ", &info->color_ceiling) == ERROR)
		return (free_all(ERROR));
	if (get_color(&info->begin, "F ", &info->color_floor) == ERROR)
		return (free_all(ERROR));
	if (get_image_path(&info->begin, "NO", 2, &g_texture[0].path) == ERROR)
		return (free_all(ERROR));
	if (get_image_path(&info->begin, "SO", 2, &g_texture[1].path) == ERROR)
		return (free_all(ERROR));
	if (get_image_path(&info->begin, "WE", 2, &g_texture[2].path) == ERROR)
		return (free_all(ERROR));
	if (get_image_path(&info->begin, "EA", 2, &g_texture[3].path) == ERROR)
		return (free_all(ERROR));
	if (get_image_path(&info->begin, "S", 1, &g_sprite.path) == ERROR)
		return (free_all(ERROR));
	return (SUCCESS);
}

static int	check_map(t_info *info)
{
	if ((check_header_footer(&info->begin) == ERROR))
		return (free_all(ERROR));
	if ((g_map_num_rows = ft_lstsize(info->begin)) < 3)
	{
		ft_putstr_fd("Error\nthere are not enought number line\n", STDOUT);
		return (free_all(ERROR));
	}
	info->column = nb_cloumn(info->begin);
	if ((put_map_in_array(info->begin, g_map_num_rows, info->column)) == ERROR)
		return (free_all(ERROR));
	if (g_info->begin)
		ft_lstclear(&g_info->begin, &free_content_node);
	if (check_character_map(g_map_num_rows, &info->orientation) == ERROR)
		return (free_all(ERROR));
	if (!info->orientation)
	{
		ft_putstr_fd("Error\nthere are probleme ", STDOUT);
		ft_putstr_fd("Error\nwith player postion\n", STDOUT);
		return (ERROR);
	}
	delete_space_in_map(info->column);
	g_info->begin = 0;
	g_info->map = g_map;
	return (SUCCESS);
}

int			parsing(t_info *info)
{
	g_map = 0;
	info->orientation = '\0';
	info->begin = 0;
	info->color_floor = 0;
	info->color_ceiling = 0;
	g_screen_width = 0;
	g_screen_height = 0;
	g_texture[0].texture_ptr = 0;
	g_texture[0].path = 0;
	g_texture[1].path = 0;
	g_texture[2].path = 0;
	g_texture[3].path = 0;
	g_sprite.path = 0;
	if (put_files_in_list(&info->begin, info->fd) == ERROR)
		return (free_all(ERROR));
	if (check_and_get_info(info) == ERROR)
		return (ERROR);
	if ((check_map(info)) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
