/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_ptr_textures_in_array.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:14:49 by lenox             #+#    #+#             */
/*   Updated: 2020/08/06 17:02:08 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_ptr_textures_in_array(t_texture texture[NUM_TEXTURE])
{
	int	bpp;
	int	size_line;
	int	endian;
	int	i;

	i = -1;
	while (++i < NUM_TEXTURE)
	{
		texture[i].texture_ptr = mlx_xpm_file_to_image(g_mlx_ptr,
		texture[i].path, &texture[i].width, &texture[i].height);
		if (!texture[i].texture_ptr)
		{
			ft_putstr_fd("Error\nFailer texture ptr\n", STDOUT);
			exit(free_all(ERROR));
		}
		texture[i].wallTexture = (int *)mlx_get_data_addr(texture[i].texture_ptr
		, &bpp, &size_line, &endian);
		if (!texture[i].wallTexture)
		{
			ft_putstr_fd("Error\nFailer texture ptr\n", STDOUT);
			exit(free_all(ERROR));
		}
	}
}
