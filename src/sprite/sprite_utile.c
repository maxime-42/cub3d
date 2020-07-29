#include "cub3d.h"

void	ft_puttexture(t_sprite *sprite, int x, int y, float sprite_size)
{
	int	textureoffsetx;
	int	distancefromtop;
	int	textureoffsety;
	int	color;

	textureoffsetx = (int)(256 * (x - (-sprite_size / 2 + sprite->spritescreenx)) * sprite->width / sprite_size) / 256;
	distancefromtop = (y) * 256 - g_window_height * 128 + sprite_size * 128;
	textureoffsety = ((distancefromtop * sprite->height) / sprite_size) / 256;
	color = sprite->data[(textureoffsety * sprite->width) + textureoffsetx];
	if (color != 0x000000)
	  	g_image_data[y * g_window_width + x] = color;
}

void	ft_drawsprite(t_sprite *sprite, float transformy, float sprite_size)
{
	int	y;
	int	x;

	x = sprite->drawstartx;
	while (x < sprite->drawendx)
	{
		if (transformy > 0 && x > 0 && x < g_window_width && transformy < sprite->buffer[x])
		{
			y = sprite->drawstarty;
			while (y < sprite->drawendy)
			{
				ft_puttexture(sprite, x, y, sprite_size);
				y++;
			}
		}
		x++;
	}
}

void	ft_getstart(t_sprite *sprite, float sprite_size, float transformy)
{
	int	spriteheight;
	int	spritewidth;

	spritewidth = sprite_size;
	sprite->drawstartx = -spritewidth / 2 + sprite->spritescreenx;
	if (sprite->drawstartx < 0)
		sprite->drawstartx = 0;
	sprite->drawendx = spritewidth / 2 + sprite->spritescreenx;
	if (sprite->drawendx >= g_window_width)
		sprite->drawendx = g_window_width - 1;
	spriteheight = sprite_size;
	sprite->drawstarty = -spriteheight / 2 + g_window_height / 2;
	if (sprite->drawstarty < 0)
		sprite->drawstarty = 0;
	sprite->drawendy = spriteheight / 2 + g_window_height / 2;
	if (sprite->drawendy >= g_window_height)
		sprite->drawendy = g_window_height - 1;
	(void)sprite_size;
	(void)transformy;
}

float	ft_calculangle(t_player *player, float x, float y)
{
	float	vectx;
	float	vecty;
	float	playertospriteangle;
	float	spriteangle;
	float	playerangle;

	vectx = x - player->x;
	vecty = y - player->y;
	playertospriteangle = atan2(vecty, vectx);
	playerangle = normalizeAngle(player->rotationAngle);
	spriteangle = playerangle - playertospriteangle;
	if (spriteangle < -3.14159)
		spriteangle += 2.0 * 3.14159;
	if (spriteangle > 3.14159)
		spriteangle -= 2.0 * 3.14159;
	spriteangle = fabs(spriteangle);
	return (spriteangle);
}


int	ft_spritevisible(t_sprite *sprite, t_player *player, int id, float sprite_size)
{
	float	spriteangle;
	float	spriteangle_end;
	float	wallspriteangle;
	float	fovsprite;

	spriteangle = fabs(ft_calculangle(player, sprite->x[id],
		sprite->y[id]));
	spriteangle_end = fabs(ft_calculangle(player, (sprite->x[id]
		+ sprite_size), (sprite->y[id] + sprite_size)));
	wallspriteangle = fabs(spriteangle_end - spriteangle);
	fovsprite = g_fov_angle / 2 + wallspriteangle;
	if (spriteangle < fovsprite)
		return (1);
	else
		return (0);
}
