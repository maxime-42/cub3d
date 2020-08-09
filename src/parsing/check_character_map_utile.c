/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_character_map_utile.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <mkayumba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 18:10:34 by user42            #+#    #+#             */
/*   Updated: 2020/08/09 14:41:09 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_character_around(char **map, int i, int j)
{
	int	ret;

	ret = 0;
	if (ft_strchr("012NSEW", map[i][j]))
	{
		if (map[i][j] == ' ')
		{
			if (map[i][j + 1] == ' ')
				ret++;
			if (map[i][j - 1] == ' ')
				ret++;
			if (map[i + 1][j] == ' ')
				ret++;
			if (map[i - 1][j] == ' ')
				ret++;
		}
	}
	return (ret == 4 ? ERROR : SUCCESS);
}
