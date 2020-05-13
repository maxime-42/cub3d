#ifndef CUB3D_H
# define CUB3D_H
#include <stdio.h>
#include <stdlib.h>
# include <math.h>
#include "../libft/libft.h"
# define STDOUT 1
# define WALL '1'
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# define SUCCESS 0
# define ERROR -1
# define COLOR_FREE_SPACE 0xFFFFFF
# define COLOR_WALL_SPACE 0x0
# define TILE_SIZE 30
# define UP_ARROW 65362
# define DOW_ARROW 65364
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define QUIT 65307


typedef struct		s_player
{
	int				x;
	int				y;
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
	int				column;
	int				height;
	char			*sprint;
	void			*map;
	t_list			*begin;
	int				color_c[3];
	int				color_f[3];
	int				fd;
	t_player		player;
}					t_info;

t_info				*g_info;
void				*g_mlx_ptr;
void				*g_img_ptr;
void				*g_win_mlx;
int					*g_image_data;
int					g_width;
int					g_height;

int					get_resolution(t_info *info);
int					get_texture(t_info *info);
int					get_sprint(t_info *info);
int					get_color(t_info *ctrl);
int					put_map_in_list(t_list **begin, int fd);
void				print_list(t_list *begin);
int					put_map_in_tab_char(void *ptr, t_list *begin);
int					check_character_map(t_list *begin);
void				free_list(void *line);
int					free_struct(t_info *info, int code_return);
int					put_map_in_array(t_info *info, t_list *begin);
int					parse_map(t_info *info);
int					draw(t_info *info);
int					keyPressed(int keyCode);
int					get_fd(t_info *info, char *name_file);
int					createImg();
int					freeAll(int codeReturn);
void				renderMap(char **map);
void				renderPlayer(t_player *player);
void				get_PositionPlayer(char **map, int *y, int *x);
int					keyRelease(int keyCode);
void				print_map(char **array);
void				twoDMap_PlayerMovement(t_info *info);
#endif
