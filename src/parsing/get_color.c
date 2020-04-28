#include "../../include/cub3d.h"

static int	free_color(char *line1, char *line2)
{
	ft_putstr_fd("Error\n: Color\n", STDOUT);
	if (line1)
		free(line1);
	if (line2)
		free(line2);
	line1 = 0;
	line2 = 0;
	return (ERROR);
}

static int	get_value_color(int *color, char *line1, char *fmt)
{
	char	*line2;
	int	count;

	count = -1;
	if ((ft_strncmp(line1, fmt, 2)) != 0)
		return (ERROR);
	line1 += 2;
	while (++count <= 2)
	{
		if (count == 2)
			line2 = ft_strchr(line1, '\0');
		else
			line2 = ft_strchr(line1, ',');
		color[count] = ft_atoi(line1);
		if ((int)(line2 - line1) != lenght_nbr(color[count]))
			return (ERROR);
		line1 = line2 + 1;
	}
	return (SUCCES);
}

int		get_color(t_info *info)
{
	char	*color_f;
	char	*color_c;

	color_f = 0;
	color_c = 0;
	if (get_next_line(info->fd, &color_f) == ERROR)
		return (free_color(color_f, color_c));
	if (get_next_line(info->fd, &color_c) == ERROR)
		return (free_color(color_f, color_c));
	if ((get_value_color(info->color_f, color_f, "F ")) == ERROR)
		return (free_color(color_f, color_c));
	if ((get_value_color(info->color_c, color_c, "C ")) == ERROR)
		return (free_color(color_f, color_c));
	free(color_f);
	free(color_c);
	return (SUCCES);
}
