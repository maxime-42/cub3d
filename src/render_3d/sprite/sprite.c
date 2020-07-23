#include "cub3d.h"

void	ft_puttexture(t_sprite *sprite, int x, int y, float sprite_size)
{
	int		textureoffsetx;
	int		distancefromtop;
	int		textureoffsety;
	int		color;

	textureoffsetx = (int)(256 * (x - (-sprite_size / 2 + sprite->spritescreenx)) * sprite->width / sprite_size) / 256;
	distancefromtop = (y) * 256 - g_window_height * 128 + sprite_size * 128;
	textureoffsety = ((distancefromtop * sprite->height) / sprite_size) / 256;
	color = sprite->data[(textureoffsety * sprite->width) + textureoffsetx];
	/* if (color == 0xFFFFFF) */
	/* 	color = 0xFFFF00; */
	g_image_data[y * g_window_width + x] = color;
}

void	ft_drawsprite(t_sprite *sprite, float transformy, float sprite_size)
{
	int		y;
	int		x;

	x = sprite->drawstartx;
	/* printf("drawstartx = %d\n", sprite->drawstartx); */
	/* printf("sprite->drawendx = %d\n", sprite->drawendx); */
	while (x < sprite->drawendx)
	{
		if (transformy > 0 && x > 0 && x < g_window_width /* && transformy < sprite->buffer[x] */)
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
	int		spriteheight;
	int		spritewidth;

	/* spritewidth = sprite_size; */
	spritewidth =  abs((g_window_height / transformy));
	sprite->drawstartx = (-spritewidth / 2) + sprite->spritescreenx;
	if (sprite->drawstartx < 0)
		sprite->drawstartx = 0;
	/* printf("spritewidth = %d\n", spritewidth); */
	sprite->drawendx = (spritewidth / 2) + sprite->spritescreenx;
	/* printf("sprite->drawendx = %d\n", sprite->drawendx); */
	if (sprite->drawendx >= g_window_width)
		sprite->drawendx = g_window_width - 1;
	/* spriteheight = sprite_size; */
	spriteheight  = (g_window_height / transformy);
	sprite->drawstarty = -spriteheight / 2 + g_window_height / 2;
	if (sprite->drawstarty < 0)
		sprite->drawstarty = 0;
	sprite->drawendy = spriteheight / 2 + g_window_height / 2;
	if (sprite->drawendy >= g_window_height)
		sprite->drawendy = g_window_height - 1;
	(void)sprite_size;
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

int		ft_spritevisible(t_sprite *sprite, t_player *player, int id, float sprite_size)
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

float	ft_gettransformy(t_sprite *sprite, t_player *player, int id)
{
	float	spritex;
	float	spritey;
	float	invdet;
	float	transformx;
	float	transformy;

	spritex = sprite->x[id] - player->x;
	spritey = sprite->y[id] - player->y;
	invdet = 1.0 / (sprite->planx * sprite->diry - sprite->dirx * sprite->plany);
	/* printf("sprite->planx = %f\n", sprite->planx); */
	/* printf("sprite->diry = %f\n", sprite->diry); */
	/* printf("sprite->dirx = %f\n", sprite->dirx); */
	/* printf("sprite->plany = %f\n", sprite->plany); */
	transformx = invdet * (sprite->diry * spritex - sprite->dirx * spritey);
	transformy = invdet * (-sprite->plany * spritex + sprite->planx * spritey);
	sprite->spritescreenx = (int)((g_window_width / 2) * (1 + -transformx / transformy));
	return (transformy);
}

void	ft_switch(t_sprite *sprite, int i, int j)
{
	float	temp_dist;
	float	temp_y;
	float	temp_x;

	temp_dist = sprite->distance[j];
	temp_x = sprite->x[j];
	temp_y = sprite->y[j];
	sprite->distance[j] = sprite->distance[i];
	sprite->x[j] = sprite->x[i];
	sprite->y[j] = sprite->y[i];
	sprite->distance[i] = temp_dist;
	sprite->x[i] = temp_x;
	sprite->y[i] = temp_y;
}

void	ft_sortsprite(t_sprite *sprite)
{
	int		j;
	int		i;

	i = -1;
	while (i++ < sprite->nb_sprite)
	{
		j = i + 1;
		while (j < sprite->nb_sprite)
		{
			if (sprite->distance[j] > sprite->distance[i])
				ft_switch(sprite, i, j);
			j++;
		}
	}
}

void	ft_spritedistance(t_sprite *sprite, t_player *player)
{
	int id;

	id = 0;
	while (id < sprite->nb_sprite)
	{
		sprite->distance[id] = distanceBetweenPoints(player->x, player->y, sprite->x[id], sprite->y[id]);
		id++;
	}
}

void	ft_zero(t_sprite *sprite)
{
	sprite->drawstartx = 0;
	sprite->drawendx = 0;
	sprite->drawstarty = 0;
	sprite->drawendy = 0;
	sprite->spritescreenx = 0;
}

void	ft_putsprite(t_sprite *sprite, t_player *player)
{
	float	distanceprojection;
	float	sprite_size;
	int	id;
	float	transformy;

	id = 0;
	ft_spritedistance(sprite, player);
	ft_sortsprite(sprite);
	while (id < sprite->nb_sprite)
	{
		distanceprojection = (g_window_width / 2) / tan(g_fov_angle / 2);
		sprite_size = (g_tile_size * 0.5 / sprite->distance[id]) * distanceprojection;
		ft_zero(sprite);
		if (ft_spritevisible(sprite, player, id, sprite_size) == 1)
		{
			transformy = ft_gettransformy(sprite, player, id);
			ft_getstart(sprite, sprite_size, transformy);
			ft_drawsprite(sprite, transformy, sprite_size);
		}
		id++;
	}
	(void)distanceprojection;
	(void)sprite_size;
	(void)id;
	(void)transformy;
}
