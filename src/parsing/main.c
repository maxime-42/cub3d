#include "cub3d.h"

void	delete_space_in_map(int column)
{
	int	i;
	int	j;

	i = -1;
	while (g_map[++i])
	{
		j = -1;
		while (g_map[i][++j])
		{
			if (g_map[i][j] == ' ')
				g_map[i][j] = '1';
		}
		while (j < column)
			g_map[i][j++] = '1';
	}
}

void	print_tab()
{
	int	i;

	i = 0;

	while (g_map && g_map[i])
	{
		printf("%s\n", g_map[i]);
		i++;
	}
}

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
			return(ERROR);
		}
		if (!(node = ft_lstnew(line)))
		{
			ft_putstr_fd("Error\nmalloc failed for create node\n", STDOUT);
			return(ERROR);
		}
		ft_lstadd_back(begin, node);
	}
	if (close(fd) != SUCCESS)
	{
			ft_putstr_fd("Error\nclose file\n", STDOUT);
			return(ERROR);
	}
	return (SUCCESS);
}

static int check_and_get_info(t_info *info)
{
	if (get_window_size(&info->begin) == ERROR)
			return(freeAll(ERROR));
	if (get_color(&info->begin, "C ", &info->color_ceiling) == ERROR)
			return(freeAll(ERROR));
	if (get_color(&info->begin, "F ", &info->color_floor) == ERROR)
			return(freeAll(ERROR));
	if (get_image_path(&info->begin, "NO", 2, &g_texture[0].path) == ERROR)
		return(freeAll(ERROR));
	if (get_image_path(&info->begin, "SO", 2, &g_texture[1].path) == ERROR)
		return(freeAll(ERROR));
	if (get_image_path(&info->begin, "WE", 2, &g_texture[2].path) == ERROR)
		return(freeAll(ERROR));
	if (get_image_path(&info->begin, "EA", 2, &g_texture[3].path) == ERROR)
		return(freeAll(ERROR));
	if (get_image_path(&info->begin, "S", 1, &g_sprite.path) == ERROR)
		return(freeAll(ERROR));
	return (SUCCESS);
}

static int check_map(t_info *info)
{

	int	column;


	if ((check_header_footer(&info->begin) == ERROR))
		return(freeAll(ERROR));
	if ((g_map_num_rows = ft_lstsize(info->begin)) < 3)
	{
		ft_putstr_fd("Error\nmaybe there are not enought number line\n", STDOUT);
		return(freeAll(ERROR));
	}
	/* if ((check_character_map(info->begin)) == ERROR) */
	/* 	return(freeAll(ERROR)); */
	/* if ((put_the_same_number_of_column(&info->begin)) == ERROR) */
	/* 	return(freeAll(ERROR)); */
	column = nb_cloumn(info->begin);
	info->column = column;
	if ((put_map_in_array(info->begin, g_map_num_rows, column)) == ERROR)
		return (freeAll(ERROR));
	if (g_info->begin)
		ft_lstclear(&g_info->begin, &freeContentNode);
	if (check_character_map(g_map_num_rows, &info->orientation) == ERROR)
		return (freeAll(ERROR));
	delete_space_in_map(column);
	g_info->begin = 0;
	g_info->map = g_map;
	//return(freeAll(ERROR));
	return (SUCCESS);
}

int	parsing(t_info *info)
{
	g_map = 0;
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
		return(freeAll(ERROR));
	if (check_and_get_info(info) == ERROR)
		return (ERROR);
	if ((check_map(info)) == ERROR)
		return(ERROR);
	/* print_tab(); */
	//print_list(info->begin);
	//freeAll(ERROR);
	return (SUCCESS);
	//	return (ERROR);
}
