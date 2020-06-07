#include "cub3d.h"

/* drawSquare: cette fonction dessine un carre dans un tableau a une dimension
	line_Column = se compote comme une line dans la premiere boucle et comme une colonne dans la deuxieme boucle
	size = la taille du carré
	color = la couleur du carré

*/

void	drawRect(int line_Column, int size, int color)
{
	int	y;
	int	x;

	y = -1;
	while (++y < size)//parcout line
	{
		x = -1;
		while (++x < size)// paracourt de la colone
		{
			g_image_data[line_Column++] = color;//parcourt chaque colonne
		}
		line_Column = line_Column - x;//on reprend la valeur de la colone initial
		line_Column = line_Column + WINDOW_WIDTH;// passer a la line suivant
	}
}


void	Rect(int corX, int corY, int width, int height, int color)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < height)
	{
		while (j < width)
		{
			g_image_data[(i + corY - width/2) * WINDOW_WIDTH + (j + corX - height/2)] = color;
			j++;
		}
		j = 0;
		i++;
	}
}
