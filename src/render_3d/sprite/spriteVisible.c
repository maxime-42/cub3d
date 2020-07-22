#include "cub3d.h"

int	spritevisible(t_sprite *sprite, t_player *player, float sprite_size)
{
	float	vectX;
	float	vectY;
	float	vectX_end;
	float	vectY_end;
	float	playertospriteangle;
	float	playertospriteangle_end;
	float 	spriteangle;
	float 	spriteangle_end;
	float	playerangle;

	vectX = sprite->x - player->x;
	vectY = sprite->y - player->y;
	vectX_end = (sprite->x + sprite_size) - player->x;
	vectY_end = (sprite->y + sprite_size) - player->y;
	playertospriteangle  = atan2(vectY, vectX);//atan
	playertospriteangle_end  = atan2(vectY_end, vectX_end);
	playerangle = normalizeAngle(player->rotationAngle);
	spriteangle = playerangle - playertospriteangle;
	spriteangle_end = playerangle - playertospriteangle_end;
			
	if (spriteangle < -3.14159)
			spriteangle += 2.0 * 3.14159;
	if (spriteangle > 3.14159)
			spriteangle -= 2.0 * 3.14159;
	if (spriteangle_end < -3.14159)
			spriteangle_end += 2.0 * 3.14159;
	if (spriteangle_end > 3.14159)
			spriteangle_end -= 2.0 * 3.14159;
	spriteangle = fabs(spriteangle);
	spriteangle_end = fabs(spriteangle_end);
	float wallspriteangle = fabs(spriteangle_end - spriteangle);
	float fovSprite = FOV_ANGLE / 2 + wallspriteangle;
	if(spriteangle < fovSprite)
		return (1);
	else
		return (0);
}