#include <stdlib.h>

char	**array_char(int line, int column)
{
	char	**array;
	int		i;

	i = -1;
	if (!(array = malloc(sizeof(char *) * (line + 1))))
		return (0);
	while (++i < line)
	{
		if (!(array[i] = malloc(sizeof(char) * (column + 1))))
		{
			while (++i <= 0)
			{
				free(array[i]);
				array[i] = 0;
			}
			return (0);
		}
		/* ft_bzero(array[i], column); */
		array[i][column] = '\0';
	}
	array[line] = 0;
	return (array);
}
