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
#include "global.h"

/* # define WALL_STRIP_WIDTH 1 */
# define MAP_NUM_ROWS g_info->height
# define MAP_NUM_COLS (const int)ft_strlen(g_info->begin->content)
# define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
# define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)
# define TILE_SIZE 32
# define NUM_RAYS (WINDOW_WIDTH / WALL_STRIP_WIDTH)
# define FOV_ANGLE (60 * (M_PI / 180))
/*___________________________________________________________________________*/

# define NUM_TEXTURE 4





# define SUCCESS 0
# define ERROR -1

# define COLOR_FREE_SPACE 0xFFFFFF
# define COLOR_WALL_SPACE 0x0


# define UP_ARROW 119
# define DOWN_ARROW 115
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define TRANSLATION_RIGHT 100
# define TRANSLATION_LEFT 97
# define QUIT 65307

# define ANGLE_DOWN 0.5 * M_PI
# define ANGLE_EAST 0
# define ANGLE_WEST M_PI
# define ANGLE_UP 1.5 * M_PI

# define STDOUT 1

# define WALL '1'
# define EMPTY_SPACE '0'
# define MAX_VALUE 2147483647
# define MINIMAP_SCALE_FACTOR 0.3
# define IS_SPRITE 2


//////////////////////parsig/////////////////////////////////////////////////////////////////////////////

int					get_Screen_Size(t_info *info);
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
void				freeContentNode(void *line);
int					free_texture(t_texture texture[NUM_TEXTURE]);
int					checkTexture(int fd, t_texture texture[NUM_TEXTURE]);
void				getTexture(t_texture texture[NUM_TEXTURE]);
int					get_path_sprite(int fd, t_sprite *sprite);

int				spritevisible(t_sprite *sprite, t_player *player, float sprite_size);
void			putsprite(t_sprite *sprite);

void		init_sprite(t_sprite *sprite, char **map, float rotationangle);

#endif
