/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:43:55 by lenox             #+#    #+#             */
/*   Updated: 2020/08/06 16:45:12 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			check_argument(t_info *info, int nb_arg, char **arg_array)
{
	info->screenshoot = 0;
	if (nb_arg == 3)
	{
		if (!ft_strcmp("--save", arg_array[2]))
		{
			info->screenshoot = 1;
			if (check_file_extension(arg_array[1], ".cub") == ERROR)
				exit(ERROR);
		}
		else
		{
			ft_putstr_fd("Error\nwrong argument\n", STDOUT);
			exit(ERROR);
		}
	}
	else if (nb_arg != 2)
	{
		ft_putstr_fd("Error\nwrong argument\n", STDOUT);
		exit(ERROR);
	}
	if (nb_arg == 2)
	{
		if (check_file_extension(arg_array[1], ".cub") == ERROR)
			exit(ERROR);
	}
}
