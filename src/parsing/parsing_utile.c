#include "cub3d.h"

void	print_list(t_list *tmp)
{
	while (tmp)
	{
		/* printf("%s\n", (char *)tmp->content); */
		/* printf("strlen = %d\n", (int)ft_strlen((char *)tmp->content)); */
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

t_list	*get_node( t_list **begin, char *search, int n)
{
	t_list	*node;

	node = ft_list_find(*begin, search, n, &ft_memcmp);
	if (!node)
	{
		return (0);
	}
	if (node == ft_lstlast(*begin))
	{
		/* ft_putstr_fd("Error\nnothing else must be at the end except wall map\n", STDOUT); */
		return (0);
	}
	return (node);
}
