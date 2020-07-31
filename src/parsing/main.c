#include "cub3d.h"

void	print_list(t_list *tmp)
{
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
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

int my_compare(char *s1, char *s2, size_t nbr_char)
{
	while (ft_isspace(*s1))
		s1++;
	if (!ft_memcmp(s1, s2, nbr_char))
	{
		return (SUCCESS);
	}
	return (ERROR);
}

static		int	put_files_in_list(t_list **begin, int fd)
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

int	parsing(t_info *info)
{
	info->begin = 0;
	g_screen_width = 0;
	g_screen_height = 0;
	put_files_in_list(&info->begin, info->fd);
	get_window_size(&info->begin);
	print_list(info->begin);
	/* printf("\ng_screen_height = %d\n", g_screen_height); */

	return(freeAll(ERROR));
	/* if (checkTexture(info->fd, g_texture) == ERROR) */
	/* 	return (free_struct(info, ERROR)); */
	/* if (get_path_sprite(info->fd, &g_sprite)) */
	/* 	return (free_struct(info, ERROR)); */
	/* if (get_color(info) == ERROR) */
	/* 	return (free_struct(info, ERROR)); */
	/* if (put_map_in_list(&info->begin, info->fd) == ERROR) */
	/* 	return (free_struct(info, ERROR)); */
	/* if (check_character_map(info->begin) == ERROR) */
	/* 	return(freeAll(ERROR)); */
	/* if (put_map_in_array(info, info->begin) == ERROR) */
	/* 	return(freeAll(ERROR)); */
	/* if (put_the_same_number_of_column(info->begin) == ERROR) */
	/* 	return(freeAll(ERROR)); */
	/* if (!g_info->orientation) */
	/* { */
	/* 	ft_putstr_fd("Error\nThere is not an orientation character\n", STDOUT); */
	/* 	return(freeAll(ERROR)); */
	/* } */
	return (SUCCESS);
}
