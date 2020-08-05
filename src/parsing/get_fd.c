/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <mkayumba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:09:54 by user42            #+#    #+#             */
/*   Updated: 2020/08/05 17:10:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_file_descriptor(t_info *info, char *name_file)
{
	if ((info->fd = open(name_file, O_RDONLY)) < 0)
	{
		ft_putstr_fd("Error\n failure open file\n", STDOUT);
		return (ERROR);
	}
	return (SUCCESS);
}
