#include "cub3d.h"

static int		create_file(char *fileName)
{
	int	fd;
	if (!((fd = open(fileName, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) > 0))
	{
			ft_putstr_fd("Error\nin while creating file bmp\n", STDOUT);
			freeAll(ERROR);
	}
	return (fd);
}

static void		create_header(t_bmp_file *infoBmpFile)
{
	infoBmpFile->byteType[0] = 0x42;
	infoBmpFile->byteType[1] = 0x4D;
	infoBmpFile->byteSize = (WINDOW_WIDTH * WINDOW_HEIGHT * 4) + 54;
	infoBmpFile->byteReserved = 0x00000000;
	infoBmpFile->byteOffset = 0x36;
	infoBmpFile->HeaderSize = 40;
	infoBmpFile->ImageWidth = WINDOW_WIDTH;
	infoBmpFile->ImageHeight = -WINDOW_HEIGHT;
	infoBmpFile->ColorPlanes = 1;
	infoBmpFile->BitsPerPixel = 32;
	infoBmpFile->compression = 0;
	infoBmpFile->ImageSize = (WINDOW_WIDTH * WINDOW_HEIGHT * 4);
	infoBmpFile->biXPelsPerMeter = WINDOW_WIDTH;
	infoBmpFile->biXPelsPerMeter = WINDOW_HEIGHT;;
	infoBmpFile->TotalColors = 0;
	infoBmpFile->ImportantColors = 0;
}

static void		write_header(int fd, t_bmp_file infoBmpFile)
{
	write(fd, &infoBmpFile.byteType, 2);
	write(fd, &infoBmpFile.byteSize, 4);
	write(fd, &infoBmpFile.byteReserved, 4);
	write(fd, &infoBmpFile.byteOffset, 4);
	write(fd, &infoBmpFile.HeaderSize, 4);
	write(fd, &infoBmpFile.ImageWidth, 4);
	write(fd, &infoBmpFile.ImageHeight, 4);
	write(fd, &infoBmpFile.ColorPlanes, 2);
	write(fd, &infoBmpFile.BitsPerPixel, 2);
	write(fd, &infoBmpFile.compression, 4);
	write(fd, &infoBmpFile.ImageSize, 4);
	write(fd, &infoBmpFile.biXPelsPerMeter, 4);
	write(fd, &infoBmpFile.biYPelsPerMeter, 4);
	write(fd, &infoBmpFile.TotalColors, 4);
	write(fd, &infoBmpFile.ImportantColors, 4);
}

static void		write_file(int fd)
{
	char	*pixel_array;
	int		image_size;
	int		i;
	int		j;

	image_size = WINDOW_WIDTH * WINDOW_HEIGHT;
	if (!(pixel_array = malloc(sizeof(char) * image_size)))
		freeAll(ERROR);
	i = 0;
	j = 0;
	while (i < image_size)
	{
		pixel_array[j++] = 	g_image_data[i] & 255;
		pixel_array[j++] = (g_image_data[i] & 255 << 8) >> 8;
		pixel_array[j++] = (g_image_data[i] & 255 << 16) >> 16;
		pixel_array[j++] = 0;
		i++;
	}
	write(fd, pixel_array, image_size);
	free(pixel_array);
}

void			bmp_exporter(char *fileName)
{
	t_bmp_file	infoBmpFile;
	int			fd;

	fd = create_file(fileName);
	create_header(&infoBmpFile);
	write_header(fd, infoBmpFile);
	write_file(fd);
	close(fd);
	(void)infoBmpFile;
}
