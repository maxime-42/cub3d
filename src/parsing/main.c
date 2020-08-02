#include "cub3d.h"

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
	/* printf("\ng_screen_height = %d\n", g_screen_height); */
	/* printf("g_screen_width = %d\n", g_screen_width); */
	/* printf("info->color_floor = %x\n", info->color_floor); */
	/* printf("texture[0].path NO = %s\n", g_texture[0].path); */
	/* free( g_texture[0].path); */
	return (SUCCESS);
}

static int check_map(t_info *info)
{
	if ((check_header_footer(&info->begin) == ERROR))
		return(freeAll(ERROR));
	if (ft_lstsize(info->begin) < 3)
	{
		ft_putstr_fd("Error\nmaybe there are not enought number line\n", STDOUT);
		return(freeAll(ERROR));
	}
	if ((check_character_map(info->begin)) == ERROR)
		return(freeAll(ERROR));
	if ((put_the_same_number_of_column(&info->begin)) == ERROR)
		return(freeAll(ERROR));
	if ((put_map_in_array(info, info->begin)) == ERROR)
		return(freeAll(ERROR));
	return (SUCCESS);
}

int	parsing(t_info *info)
{
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
	//print_list(info->begin);
	//freeAll(ERROR);
	return (SUCCESS);
	//	return (ERROR);
}
