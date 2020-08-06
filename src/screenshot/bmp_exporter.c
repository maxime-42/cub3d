/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_exporter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 13:11:07 by lenox             #+#    #+#             */
/*   Updated: 2020/08/06 18:37:05 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int		create_file(char *file_name)
{
	int	fd;

	if (!((fd = open(file_name, O_WRONLY | O_CREAT |
	O_TRUNC, S_IRUSR | S_IWUSR)) > 0))
	{
		ft_putstr_fd("Error\nin while creating file bmp\n", STDOUT);
		free_all(ERROR);
	}
	return (fd);
}

static void		create_header(t_bmp_file *info_bmp_file)
{
	info_bmp_file->byte_type[0] = 0x42;
	info_bmp_file->byte_type[1] = 0x4D;
	info_bmp_file->byte_size = (g_window_width * g_window_height * 4) + 54;
	info_bmp_file->byte_reserved = 0x00000000;
	info_bmp_file->byte_offset = 0x36;
	info_bmp_file->header_size = 40;
	info_bmp_file->image_width = g_window_width;
	info_bmp_file->image_height = -g_window_height;
	info_bmp_file->color_planes = 1;
	info_bmp_file->bits_per_pixel = 32;
	info_bmp_file->compression = 0;
	info_bmp_file->image_size = (g_window_width * g_window_height * 4);
	info_bmp_file->bits_xpels_per_meter = 2835;
	info_bmp_file->bits_xpels_per_meter = 2835;
	info_bmp_file->total_colors = 0;
	info_bmp_file->important_colors = 0;
}

static void		write_header(int fd, t_bmp_file info_bmp_file)
{
	int			r;

	r = 0;
	r = write(fd, &info_bmp_file.byte_type, 2);
	r = write(fd, &info_bmp_file.byte_size, 4);
	r = write(fd, &info_bmp_file.byte_reserved, 4);
	r = write(fd, &info_bmp_file.byte_offset, 4);
	r = write(fd, &info_bmp_file.header_size, 4);
	r = write(fd, &info_bmp_file.image_width, 4);
	r = write(fd, &info_bmp_file.image_height, 4);
	r = write(fd, &info_bmp_file.color_planes, 2);
	r = write(fd, &info_bmp_file.bits_per_pixel, 2);
	r = write(fd, &info_bmp_file.compression, 4);
	r = write(fd, &info_bmp_file.image_size, 4);
	r = write(fd, &info_bmp_file.bits_xpels_per_meter, 4);
	r = write(fd, &info_bmp_file.bits_ypels_per_meter, 4);
	r = write(fd, &info_bmp_file.total_colors, 4);
	r = write(fd, &info_bmp_file.important_colors, 4);
	(void)r;
}

static void		write_file(int fd, int imagesize)
{
	char		*pixel_array;
	int			i;
	int			j;

	if (!(pixel_array = malloc(sizeof(char) * imagesize)))
		free_all(ERROR);
	i = 0;
	j = 0;
	imagesize /= 4;
	while (i < imagesize)
	{
		pixel_array[j++] = g_image_data[i] & 255;
		pixel_array[j++] = (g_image_data[i] & 255 << 8) >> 8;
		pixel_array[j++] = (g_image_data[i] & 255 << 16) >> 16;
		pixel_array[j++] = 0;
		i++;
	}
	j = write(fd, pixel_array, imagesize *= 4);
	free(pixel_array);
}

void			bmp_exporter(char *file_name)
{
	t_bmp_file	info_bmp_file;
	int			fd;

	ft_bzero(&info_bmp_file, sizeof(t_bmp_file));
	fd = create_file(file_name);
	create_header(&info_bmp_file);
	write_header(fd, info_bmp_file);
	write_file(fd, info_bmp_file.image_size);
	close(fd);
	(void)info_bmp_file;
}
