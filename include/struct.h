#ifndef _STRUCT_H
# define _STRUCT_H
# define SIZE_PATH 64


typedef struct		s_ray
{
	float			xintercept;
	float			yintercept;
	float			xstep;
	float			ystep;
	float			wallHitX;
	float			wallHitY;
	float			wasHitVertical;
	float			vertWallHitX;
	float			vertWallHitY;
	float			horzWallHitY;
	float			horzWallHitX;
	float			rayAngle;
	int			foundVertWallHit;
	int			foundHorzWallHit;
	int			isRayFacingDown;
	int			isRayFacingUp;
	int			isRayFacingRight;
	int			isRayFacingLeft;
	float			distance;
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
	char			position;
	int				translation;
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
	int			color_ceiling;
  int				color_floor;
	int				fd;
	int			size_line;  
	char			orientation;
}					t_info;

typedef struct		s_texture
{
	char		*path;
	void		*texture_ptr;
	int			*wallTexture;
	int			height;
	int			width;
}					t_texture;


typedef struct s_wall
{
	float	correctWallDistance;
	float	distanceProjectionPlane;
	int		wallStripHeight;
	int		wallTop;
	int		wallBottom;
}				t_wall;

typedef struct		s_bmp_file
{
	char			byteType[2];
	unsigned int	byteSize;
	unsigned int	byteReserved;
	unsigned int	byteOffset;
	unsigned		HeaderSize;
	int				ImageWidth;
	int				ImageHeight;
	unsigned short	ColorPlanes;
	unsigned short	BitsPerPixel;
	unsigned int	compression;
	unsigned int	ImageSize;
	int				bitsXPelsPerMeter;
	int				bitsYPelsPerMeter;
	unsigned int	TotalColors;
	unsigned int	ImportantColors;
}				   t_bmp_file;


 typedef struct		s_sprite
{
	float		diry;
	float		dirx;
	float		plany;
	float		planx;
  	int		*data;
	void		*ptr;
	int		size_l;
	float		*distance;
	float		angle;
	int		width;
	int		bpp;
	int		endian;
	int		height;
	float		*x;
	float		*y;
	char		*path;
	int		nb_sprite;
	float		*buffer;
	int		spritescreenx;
	int		drawstarty;
	int		drawendy;
	int		drawstartx;
	int		drawendx;
}			t_sprite;

#endif
