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
	float			x;
	float			y;
	int				radius;
	int				turnDirection;
	int				walkDirection;
	float			rotationAngle;
	float			moveSpeed;
	float			rotationSpeed;
}					t_player;

typedef struct		s_info
{
	char			*texture[5];
	int				nline_map;
	int				column;// je l'utiliser que durant le parsing
	int				height;//je l'utiliser que durant   le parsing
	char			*sprint;
	void			*map;
	t_list			*begin;
	int				color_c[3];
	int				color_f[3];
	int				fd;
	char			orientation;
	int				keyCode;
}					t_info;

#endif
