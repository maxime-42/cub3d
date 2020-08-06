/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <mkayumba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:12:43 by user42            #+#    #+#             */
/*   Updated: 2020/08/06 12:43:08 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			check_file_extension(char *line, char *extension_name)
{
	int		end;

	end = (int)ft_strlen(line) - 1;
	while (end && ft_isspace(line[end]))
		line[end--] = '\0';
	end -= 3;
	if (end >= 4)
	{
		if (ft_strcmp(line + end, extension_name))
		{
			ft_putstr_fd("Error\nit is not xpm extension\n", STDOUT);
			return (ERROR);
		}
	}
	else
	{
		ft_putstr_fd("Error\nthe are trouble with name file\n", STDOUT);
		return (ERROR);
	}
	return (SUCCESS);
}

int			get_image_path(t_list **begin, char *name, int n, char **dest)
{
	t_list	*node;
	char	*line;

	if (!(node = get_node(begin, name, n)))
	{
		ft_putstr_fd("Error\nit is not possible to load image\n", STDOUT);
		return (ERROR);
	}
	line = (char *)node->content;
	line += 2;
	line += skip_space(line);
	if (check_file_extension(line, ".xpm") == ERROR)
		return (ERROR);
	dest[0] = ft_strdup(line);
	ft_list_remove_one_if(begin, node->content, &ft_strcmp, &free_content_node);
	(void)dest;
	return (SUCCESS);
}
