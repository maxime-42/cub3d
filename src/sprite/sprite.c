#include "cub3d.h"

static void	get_sprite(t_sprite *sprite)
{
	int		bpp;
	int		size_line;
	int		endian;

	sprite->sprite_ptr = mlx_xpm_file_to_image(g_mlx_ptr, sprite->path, &sprite->width, &sprite->height);
	sprite->data = (int *)mlx_get_data_addr(sprite->sprite_ptr, &bpp, &size_line, &endian);
	if (!sprite->sprite_ptr)
	{
		ft_putstr_fd("Error\nFailer sprite ptr\n", STDOUT);
		exit (freeAll(ERROR));
	}
}




void	putsprite(t_param *param)
{
  	int		textureoffsetx;
	int		distancefromtop;
	int		textureoffsety;
	float		distanceprojection;
	int		sprite;
	float		sprite_size;
	int		y;
	int		id = 0;

	sprite->distance = distanceBetweenPoints(player->x, player->y, sprite->x, sprite->y);
	distanceprojection = (WINDOW_WIDTH / 2) / tan(FOV / 2);
	sprite_size = (TILE_SIZE * 0.5 / sprite->distance ) * distanceprojection;
	if (ft_spritevisible(param, sprite_size) == 1)
	{
		float spriteX = param->sprite.x[id] - param->player.x;
		float spriteY = param->sprite.y[id] - param->player.y;
	//	printf("spriteX = %f     spriteY = %f\n",spriteX, spriteY);
		float invDet = 1.0 / (sprite->planx * sprite->diry - sprite->dirx * param->plany);
		float transformX = invDet * (sprite->dirY * spriteX - sprite->dirx * spritey);
		float transformY = invDet * (-param->plany * spritex + param->planx * spritey);
		int spriteScreenX = (int)((WINDOW_WIDTH / 2) * (1 + -transformX / transformY));
		int spriteHeight = sprite_size;
		int drawStartY = -spriteHeight / 2 + WINDOW_HEIGHT / 2;
		if(drawStartY < 0)
		  drawStartY = 0;
		int drawEndY = spriteHeight / 2 + WINDOW_HEIGHT / 2;
		if(drawEndY >= WINDOW_HEIGHT)
			drawEndY = WINDOW_HEIGHT - 1;
		int spriteWidth = sprite_size;
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if(drawStartX < 0)
		  drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if(drawEndX >= WINDOW_WIDTH) drawEndX = WIN_WIDTH - 1;
			sprite = drawStartX;
		while (sprite < drawEndX)
		{
			if(transformY > 0 && sprite > 0 && sprite < WINDOW_WIDTH && transformY < param->sprite.buffer[sprite])
			{
				y = drawStartY;
				while (y < drawEndY)
				{
					textureoffsetx = (int)(256 * (sprite - (-sprite_size / 2 + spriteScreenX)) * param->sprite.width / sprite_size) / 256;
					distancefromtop = (y) * 256 - WIN_HEIGHT * 128 + sprite_size * 128;
					textureoffsety = ((distancefromtop * param->sprite.height) / sprite_size) / 256;
					int color = sprite->data[(textureoffsety * param->sprite.width) + textureoffsetx];
					sprite->data[y * WIN_WIDTH + sprite] = color;
					y++;
				}
				sprite++;
			}
		}
}
