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
	infoBmpFile->byteSize = (g_window_width * g_window_height * 4) + 54;
	infoBmpFile->byteReserved = 0x00000000;
	infoBmpFile->byteOffset = 0x36;
	infoBmpFile->HeaderSize = 40;
	infoBmpFile->ImageWidth = g_window_width;
	infoBmpFile->ImageHeight = -g_window_height;
	infoBmpFile->ColorPlanes = 1;
	infoBmpFile->BitsPerPixel = 32;
	infoBmpFile->compression = 0;
	infoBmpFile->ImageSize = (g_window_width * g_window_height * 4);
	infoBmpFile->bitsXPelsPerMeter = 2835;
	infoBmpFile->bitsXPelsPerMeter = 2835;
	infoBmpFile->TotalColors = 0;
	infoBmpFile->ImportantColors = 0;
}

static void		write_header(int fd, t_bmp_file infoBmpFile)
{
	 int	r;  

	 r = 0;
	r = write(fd, &infoBmpFile.byteType, 2);
	r = write(fd, &infoBmpFile.byteSize, 4);
	r = write(fd, &infoBmpFile.byteReserved, 4);
	r = write(fd, &infoBmpFile.byteOffset, 4);
	r = write(fd, &infoBmpFile.HeaderSize, 4);
	r = write(fd, &infoBmpFile.ImageWidth, 4);
	r = write(fd, &infoBmpFile.ImageHeight, 4);
	r = write(fd, &infoBmpFile.ColorPlanes, 2);
	r = write(fd, &infoBmpFile.BitsPerPixel, 2);
	r = write(fd, &infoBmpFile.compression, 4);
	r = write(fd, &infoBmpFile.ImageSize, 4);
	r = write(fd, &infoBmpFile.bitsXPelsPerMeter, 4);
	r = write(fd, &infoBmpFile.bitsYPelsPerMeter, 4);
	r = write(fd, &infoBmpFile.TotalColors, 4);
	r = write(fd, &infoBmpFile.ImportantColors, 4);
	(void)r;
}

static void		write_file(int fd, int ImageSize)
{
	char		*pixel_array;
	int		i;
	int		j;


	if (!(pixel_array = malloc(sizeof(char) * ImageSize)))
		freeAll(ERROR);
	i = 0;
	j = 0;
	ImageSize /= 4;
	while (i < ImageSize)
	{
		pixel_array[j++] = g_image_data[i] & 255;
		pixel_array[j++] = (g_image_data[i] & 255 << 8) >> 8;
		pixel_array[j++] = (g_image_data[i] & 255 << 16) >> 16;
		pixel_array[j++] = 0;
		i++;
	}
	j = write(fd, pixel_array, ImageSize *= 4);
	free(pixel_array);
}

void			bmp_exporter(char *fileName)
{
	t_bmp_file	infoBmpFile;
	int			fd;

	fd = create_file(fileName);
	create_header(&infoBmpFile);
	write_header(fd, infoBmpFile);
	write_file(fd, infoBmpFile.ImageSize);
	close(fd);
	(void)infoBmpFile;

}
