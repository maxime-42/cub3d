/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_exporter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 13:11:07 by lenox             #+#    #+#             */
/*   Updated: 2020/08/06 13:19:23 by lenox            ###   ########.fr       */
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
	info_bmp_file->byteType[0] = 0x42;
	info_bmp_file->byteType[1] = 0x4D;
	info_bmp_file->byteSize = (g_window_width * g_window_height * 4) + 54;
	info_bmp_file->byteReserved = 0x00000000;
	info_bmp_file->byteOffset = 0x36;
	info_bmp_file->HeaderSize = 40;
	info_bmp_file->ImageWidth = g_window_width;
	info_bmp_file->ImageHeight = -g_window_height;
	info_bmp_file->ColorPlanes = 1;
	info_bmp_file->BitsPerPixel = 32;
	info_bmp_file->compression = 0;
	info_bmp_file->ImageSize = (g_window_width * g_window_height * 4);
	info_bmp_file->bitsXPelsPerMeter = 2835;
	info_bmp_file->bitsXPelsPerMeter = 2835;
	info_bmp_file->TotalColors = 0;
	info_bmp_file->ImportantColors = 0;
}

static void		write_header(int fd, t_bmp_file info_bmp_file)
{
	int			r;

	r = 0;
	r = write(fd, &info_bmp_file.byteType, 2);
	r = write(fd, &info_bmp_file.byteSize, 4);
	r = write(fd, &info_bmp_file.byteReserved, 4);
	r = write(fd, &info_bmp_file.byteOffset, 4);
	r = write(fd, &info_bmp_file.HeaderSize, 4);
	r = write(fd, &info_bmp_file.ImageWidth, 4);
	r = write(fd, &info_bmp_file.ImageHeight, 4);
	r = write(fd, &info_bmp_file.ColorPlanes, 2);
	r = write(fd, &info_bmp_file.BitsPerPixel, 2);
	r = write(fd, &info_bmp_file.compression, 4);
	r = write(fd, &info_bmp_file.ImageSize, 4);
	r = write(fd, &info_bmp_file.bitsXPelsPerMeter, 4);
	r = write(fd, &info_bmp_file.bitsYPelsPerMeter, 4);
	r = write(fd, &info_bmp_file.TotalColors, 4);
	r = write(fd, &info_bmp_file.ImportantColors, 4);
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
	write_file(fd, info_bmp_file.ImageSize);
	close(fd);
	(void)info_bmp_file;
}
