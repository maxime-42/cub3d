/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <mkayumba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 18:11:49 by user42            #+#    #+#             */
/*   Updated: 2020/08/05 18:14:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		print_tab(void)
{
	int	i;

	i = 0;
	while (g_map && g_map[i])
	{
		printf("%s\n", g_map[i]);
		i++;
	}
}

void		print_list(t_list *tmp)
{
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
}

void		delete_space_in_map(int column)
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

int			skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	return (i);
}

int			skip_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (i);
}

t_list		*get_node(t_list **begin, char *search, int n)
{
	t_list	*node;

	node = ft_list_find(*begin, search, n, &ft_memcmp);
	if (!node)
	{
		return (0);
	}
	if (node == ft_lstlast(*begin))
	{
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
