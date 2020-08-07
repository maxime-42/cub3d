/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling_and_floor.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <mkayumba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:51:35 by user42            #+#    #+#             */
/*   Updated: 2020/08/07 15:00:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor(void)
{
	int i;
	int j;
	int	color;

	i = 0;
	j = 0;
	color = g_info->color_floor;
	while (i < (g_window_height / 2))
	{
		while (j < g_window_width)
		{
			g_image_data[(i + g_window_height / 2) *
			g_window_width + (j + 0)] = color;
			j++;
		}
		j = 0;
		i++;
	}
}

void	draw_ceiling(void)
{
	int i;
	int j;
	int	color;

	i = 0;
	j = 0;
	color = g_info->color_ceiling;
	while (i < (g_window_height / 2))
	{
		while (j < g_window_width)
		{
			g_image_data[(i + 0) * g_window_width + (j + 0)] = color;
			j++;
		}
		j = 0;
		i++;
	}
}
