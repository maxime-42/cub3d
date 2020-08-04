#include "cub3d.h"



/* void		cpy_without_space(char *dest, char *src, int size) */
/* { */
/* 	int		index_dest; */
/* 	int		r; */

/* 	index_dest = 0; */
/* 	while (*src) */
/* 	{ */
/* 		src += skip_space(src); */
/* 		if (*src) */
/* 			dest[index_dest++] = *src; */
/* 		src++; */
/* 	} */
/* 	r = size - index_dest; */
/* 	/\* printf("r = %d\n", r ); *\/ */
/* 	while (r > 0) */
/* 	{ */
/* 		/\* printf("hellow"); *\/ */
/* 		dest[index_dest++] = '1'; */
/* 		r--; */
/* 	} */
/* } */

/* int			put_the_same_number_of_column(t_list **begin) */
/* { */
/* 	char	*line; */
/* 	int		size; */
/* 	t_list	*node; */

/* 	node = *begin; */
/* 	size = nb_cloumn(node); */
/* 	while (node) */
/* 	{ */
/* 		if (!(line = malloc(sizeof(char) * (size + 1)))) */
/* 		{ */
/* 			ft_putstr_fd("Error\nmalloc failure\n", STDOUT); */
/* 			return (ERROR); */
/* 		} */
/* 		ft_bzero(line, size + 1); */
/* 		cpy_without_space(line, node->content, size); */
/* 		free((char *)node->content); */
/* 		node->content = line; */
/* 		node = node->next; */
/* 	} */
/* 	return (SUCCESS); */
/* } */
