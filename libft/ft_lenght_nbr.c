int		lenght_nbr(int nb)
{
	int	size_nb;
	int	result;

	result = 1;
	size_nb  = 0;
	while (result)
	{
		result = nb /  10;
		nb = result;
		size_nb++;
	}
	return (size_nb);
}
