#include "../../include/cub3d.h"

static	int	free_line(char *line)
{
	if (line)
		free(line);
	return (ERROR);
	line = 0;
}

static int	get_value_resol(char *line1, char *line2)
{
	int	nb;
	int	size_nb;

	nb = ft_atoi(line1);
	size_nb = line2 - line1;
	if (size_nb != lenght_nbr(nb))
	{
		ft_putstr_fd("Error\nSize resolution", STDOUT);
		return (ERROR);
	}
	return (nb);
}

int		get_Screen_Size(t_info *info)
{
	char	*line1;
	char	*line2;
	char	*line3;

	if (get_next_line(info->fd, &line1) == ERROR)
		return (free_line(line1));
	if (line1[0] == 'R' && line1[1] == ' ')
	{
		line2 = ft_strchr(line1 + 2, ' ');
		if ((g_screen_width = get_value_resol(line1 + 2, line2)) == ERROR)
			return (free_line(line1));
		line3 = ft_strchr(++line2, '\0');
		if ((g_screen_height = get_value_resol(line2, line3)) == ERROR)
			return (free_line(line1));
	}
	else
	{
		ft_putstr_fd("Error\n worng resolution", STDOUT);
		return (free_line(line1));
	}
	free(line1);
	return (SUCCESS);
}
