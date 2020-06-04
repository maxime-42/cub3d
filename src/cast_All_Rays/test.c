#include <stdio.h>

# define NUM_RAYS 100

void	test(double ray[NUM_RAYS])
{
	int		columnId;

	columnId = 0;
	while (columnId < NUM_RAYS)
	{
		ray[columnId] = columnId;
		printf("%f\n", ray[columnId]);
		columnId++;
	}
}

int	main(void)
{
	double	ray[NUM_RAYS];

	test(ray);
	return (0);
}
