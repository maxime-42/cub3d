#include "cub3d.h"

void			putsprite(t_sprite *sprite)
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
	distanceprojection = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
	sprite_size = (TILE_SIZE * 0.5 / sprite->distance ) * distanceprojection;
	if (spritevisible(sprite, player, sprite_size) == 1)
	{
		float spriteX = sprite->x - player->x;
		float spriteY = sprite->y - player->y;
	//	printf("spriteX = %f     spriteY = %f\n",spriteX, spriteY);
		float invDet = 1.0 / (sprite->planx * sprite->diry - sprite->dirx * sprite->plany);
		float transformX = invDet * (sprite->dirY * spriteX - sprite->dirx * sprite->y);
		float transformY = invDet * (-sprite->plany * spritex + sprite->planx * sprite->y);
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
		if(drawEndX >= WINDOW_WIDTH) drawEndX = WINDOW_WIDTH - 1;
			sprite = drawStartX;
		while (sprite < drawEndX)
		{
			if(transformY > 0 && sprite > 0 && sprite < WINDOW_WIDTH && transformY < param->sprite.buffer[sprite])
			{
				y = drawStartY;
				while (y < drawEndY)
				{
					textureoffsetx = (int)(256 * (sprite - (-sprite_size / 2 + spriteScreenX)) * param->sprite.width / sprite_size) / 256;
					distancefromtop = (y) * 256 - WINDOW_HEIGHT * 128 + sprite_size * 128;
					textureoffsety = ((distancefromtop * sprite->height) / sprite_size) / 256;
					int color = sprite->data[(textureoffsety * sprite->width) + textureoffsetx];
					sprite->data[y * WINDOW_WIDTH + sprite] = color;
					y++;
				}
				sprite++;
			}
		}
}
