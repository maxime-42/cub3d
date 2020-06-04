#include "cub3d.h"

/* drawSquare:
	cette fonction dessine un carré
	line = la line d'ou commence le dessin du carré
	size = la taille du carré
	color = la couleur du carré
*/
void	drawSquare(int line, int size, int color)
{
	int	y;
	int	x;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			g_image_data[line++] = color;
		}
		line = line - x;
		line = line + g_width;
	}
}
