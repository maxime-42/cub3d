#ifndef _STRUCT_H
# define _STRUCT_H

typedef struct		s_ray
{
	int				xintercept;
	int				yintercept;
	int				xstep;
	int				ystep;
	int				wallHitX;
	int				wallHitY;
	int				vertWallHitX;
	int				vertWallHitY;
	double			rayAngle;
	int				isRayFacingDown;
	int				isRayFacingUp;
	int				isRayFacingRight;
	int				isRayFacingLeft;
	int				foundVertWallHit;
	int				distance;
}					t_ray;

typedef struct		s_player
{
	int				x;
	int				y;
	int				test;
	int				radius;
	int				turnDirection;
	int				walkDirection;
	double			rotationAngle;
	double			moveSpeed;
	double			rotationSpeed;
}					t_player;

typedef struct		s_info
{
	char			*texture[5];
	int				nline_map;
	int				column;// je l'utiliser que durant le parsing
	int				height;//nombre de line de la map
	char			*sprint;
	void			*map;
	t_list			*begin;
	int				color_c[3];
	int				color_f[3];
	int				fd;
	int				keyCode;
}					t_info;

#endif
