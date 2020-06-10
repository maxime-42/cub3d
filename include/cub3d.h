#ifndef CUB3D_H
# define CUB3D_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include "struct.h"
#include "raycasting.h"

# define SUCCESS 0
# define ERROR -1

# define COLOR_FREE_SPACE 0xFFFFFF
# define COLOR_WALL_SPACE 0x0
# define TILE_SIZE 32

# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define QUIT 65307

# define STDOUT 1
# define WALL '1'

# define MAP_NUM_ROWS  g_info->height
# define MAP_NUM_COLS  (int)ft_strlen(g_info->begin->content)

# define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
# define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

# define FOV_ANGLE  60 * (M_PI / 180)
# define WALL_STRIP_WIDTH  1
# define NUM_RAYS WINDOW_WIDTH / WALL_STRIP_WIDTH

////////*variable globals////////////////////////////
t_info				*g_info;
t_player			g_player;
void				*g_mlx_ptr;
void				*g_img_ptr;
void				*g_win_mlx;
int					*g_image_data;
int					g_screen_width;//largeur de la fenetre
int					g_screen_height;//hauteur de la fenetre
//////////////////////////////////////////////////////

char				**g_map;
t_ray				g_ray;

//////////////////////parsig///////////////////////
int					get_Screen_Size(t_info *info);
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
int					freeAll(int codeReturn);
int					parsing_map(t_info *info);

#endif
