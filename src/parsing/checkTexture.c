#include "cub3d.h"

static	int	checkPath(char **line, char *direction, char *path)
{
	char	*linePtr;
	int		codeRet;

	if ((codeRet = ft_strncmp(line[0], direction, 5)) != 0)
	{
		codeRet = ERROR;
	}
	else
	{
		linePtr = ft_strchr(line[0], '/');
		ft_memcpy(path, linePtr+1, (size_t)ft_strlen(linePtr+1));
		free(line[0]);
		line[0] = 0;
	}
	return (codeRet);
}

int			checkTexture(int fd, t_texture texture[NUM_TEXTURE])
{
	int		count;
	char	*line;

	count = -1;
	while (++count < NUM_TEXTURE)
	{
		if ((get_next_line(fd, &line)) == ERROR)
		{
			ft_putstr_fd("Error\nfaile get next line\n", STDOUT);
			return (ERROR);
		}
		if (checkPath(&line, "NO ./", texture[count].path) == SUCCESS)
			;
		else if (checkPath(&line, "SO ./", texture[count].path) == SUCCESS)
			;
		else if (checkPath(&line, "WE ./", texture[count].path) == SUCCESS)
			;
		else if (checkPath(&line, "EA ./", texture[count].path) == SUCCESS)
			;
		else
		{
			ft_putstr_fd("Error\nWrong path texture\n", STDOUT);
			free(line);
			return (ERROR);
		}
	}
	return (SUCCESS);
}

