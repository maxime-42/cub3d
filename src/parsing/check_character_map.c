#include "cub3d.h"

int		is_wall(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == ' ')
			;
		else if (line[i] != '1')
			return (ERROR);
	}
	return (SUCCESS);
}

int		check_first_character(char *line)
{
	int	i;

	i = 0;

	while (line[i] == ' ')
		i++;
	if (!line[i] || line[i] != '1')
	{
		ft_putstr_fd("Error\nmap must begin with Wall\n", STDOUT);
		return (ERROR);
	}
	return (i);
}

int		check_character_map(int nb_line, char *orientation)
{
	int		i;
	int		j;
	int		save;

	i = 0;
	save = 0;
	g_info->orientation = '\0';
	if (is_wall(g_map[0]) == ERROR || is_wall(g_map[nb_line - 1]) == ERROR)
		return (ERROR);
	while (g_map[i + 1] && g_map[++i])
	{
		if ((j = check_first_character(g_map[i])) == ERROR)
			return (ERROR);
		while (g_map[i][++j])
		{
			if ((save = isValideCharacter(orientation, g_map[i][j])) == ERROR)
				return (ERROR);
			if (check_around_character(g_map, i, j) == ERROR)
				return (ERROR);
			if (g_map[i][j] != ' ')
				save = j;
		}
		if (g_map[i][save] != '1')
		{
			ft_putstr_fd("Error\nlast charecter must be wall", STDOUT);
			return (ERROR);
		}
	}
	if (!*orientation)
	{
		ft_putstr_fd("Error\nto many orientation", STDOUT);
		return (ERROR);
	}
	(void)orientation;
	(void)i;
	(void)j;
	(void)save;;
	(void)nb_line;
	return (SUCCESS);
}

/* static int	lastChar(char **linePrev, int previous, char *lineCurrent, int current) */
/* { */
/* 	if (lineCurrent[current] != WALL) */
/* 	{ */
/* 		ft_putstr_fd("Error\nlast character not 1\n", STDOUT); */
/* 		return (ERROR); */
/* 	} */
/* 	if (previous > current) */
/* 	{ */
/* 		if (linePrev[0][current] != WALL) */
/* 		{ */
/* 			ft_putstr_fd("Error\n1-character adj not 1\n", STDOUT); */
/* 			return (ERROR); */
/* 		} */
/* 	} */
/* 	else if (current > previous) */
/* 	{ */
/* 		if (lineCurrent[previous] != WALL) */
/* 		{ */
/* 			ft_putstr_fd("Error\n2-character adj not 1\n", STDOUT); */
/* 			return (ERROR); */
/* 		} */
/* 	} */
/* 	linePrev[0] = lineCurrent; */
/* 	return (current); */
/* } */

/* static int	valideCharacter(char character) */
/* { */
/* 	static	int direction = 0; */

/* 	if (!ft_strchr("012NSEW ", character)) */
/* 	{ */
/* 		ft_putstr_fd("Error\nunknown character\n", STDOUT); */
/* 		return(ERROR); */
/* 	} */
/* 	if (ft_strchr("NSEW", character)) */
/* 	{ */
/* 		if (!direction) */
/* 		{ */
/* 			direction = 1; */
/* 			g_info->orientation = character; */
/* 		} */
/* 		else */
/* 		{ */
/* 			ft_putstr_fd("Error\nTo many direction\n", STDOUT); */
/* 			return (ERROR); */
/* 		} */
/* 	} */
/* 	return (SUCCESS); */
/* } */

/* static int	checkFirstLine(char *currentLine) */
/* { */
/* 	int		previous; */

/* 	previous = 0; */
/* 	while (ft_isspace(currentLine[previous])) */
/* 		previous++; */
/* 	if (currentLine[previous] != WALL) */
/* 	{ */
/* 		ft_putstr_fd("Error\nThe first line have to begin with 1\n", STDOUT); */
/* 		return (ERROR); */
/* 	} */
/* 	while (currentLine[previous]) */
/* 	{ */
/* 		if (!ft_strchr("1", '1')) */
/* 		{ */
/* 			ft_putstr_fd("Error\n", STDOUT); */
/* 			ft_putstr_fd("it takes just 1 for the first line and column\n", 1); */
/* 			return(ERROR); */
/* 		} */
/* 		previous++; */
/* 	} */
/* 	return (previous - 1); */
/* } */

/* static int	lastLine(char *linePrev, int previous, char *line) */
/* { */
/* 	int		indexLine; */

/* 	indexLine = 0; */
/* 	while (line[indexLine + 1]) */
/* 	{ */
/* 		if (!ft_strchr("1 ", line[indexLine++])) */
/* 		{ */
/* 			ft_putstr_fd("Error\n", STDOUT); */
/* 			ft_putstr_fd("it takes just 1 for the last line\n", 1); */
/* 			return (ERROR); */
/* 		} */
/* 	} */
/* 	if ((previous = lastChar(&linePrev, previous, line, indexLine)) == ERROR) */
/* 		return (ERROR); */
/* 	return (SUCCESS); */
/* } */

/* int			check_character_map(t_list *begin) */
/* { */
/* 	char	*line; */
/* 	int		current; */
/* 	char	*linePrev; */
/* 	int		previous; */

/* 	line = 0; */
/* 	g_info->orientation = '\0'; */
/* 	if ((previous = checkFirstLine(linePrev = begin->content)) == ERROR) */
/* 		return (ERROR); */
/* 	while ((begin = begin->next)) */
/* 	{ */
/* 		current = 0; */
/* 		line = (char *)begin->content; */
/* 		while (line[current] && line[current + 1]) */
/* 		{ */
/* 			if (valideCharacter(line[current++]) == ERROR) */
/* 				return (ERROR); */
/* 		} */
/* 		if ((previous = lastChar(&linePrev, previous, line, current)) == ERROR) */
/* 			return (ERROR); */
/* 	} */
/* 	if (lastLine(linePrev, previous, line) == ERROR) */
/* 		return (ERROR); */
/* 	return (SUCCESS); */
/* } */
