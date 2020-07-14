
void    ft_initsprite(char **map, t_sprite *sprite)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		i = 0;
		while (map[i][j])
		{
			if (map[i][j] == '2')
			{
				sprite->x = j * TILE_SIZE + TILE_SIZE / 2;
				sprite->y = i * TILE_SIZE + TILE_SIZE / 2;
			}
			j++;
		}
	}
	sprite->angle = 0;
	sprite->ptr = 0;
	sprite->data = 0;
	sprite->bpp = 0;
	sprite->endian = 0;
	sprite->size_l = 0;
	sprite->width = 0;
	sprite->height = 0;
}

void	initVecteur(t_sprite *sprite, float rotationAngle)
{
	if (rotationAngle == ANGLE_EAST)
	{
		sprite->dirx = 1;
		sprite->diry = 0;
		sprite->planx = 0;
		sprite->plany = -0.6;	  
	}
	if (rotationangle == angle_down)
	{
		sprite->dirx = 0;
		sprite->diry = 1;
		sprite->planx = 0.6;
		sprite->plany = 0;
	}
	if (rotationangle == angle_west)
	{
		sprite->dirx = -1;
		sprite->diry = 0;
		sprite->planx = 0;
		sprite->plany = 0.6;
	}
	if (rotationangle == angle_up)
	{
		sprite->dirx = 0;
		sprite->diry = -1;
		sprite->planx = -0.6;
		sprite->plany = 0;
	} 
}
