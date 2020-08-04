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
#include "const.h"

/* # define WALL_STRIP_WIDTH 1 */
/* # define MAP_NUM_ROWS g_info->height */
/* # define MAP_NUM_COLS (const int)ft_strlen(g_info->begin->content) */
/* # define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE) */
/* # define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE) */
/* /\* # define TILE_SIZE 32 *\/ */
/* # define NUM_RAYS (WINDOW_WIDTH / WALL_STRIP_WIDTH) */
/* # define FOV_ANGLE (60 * (M_PI / 180)) */
/*___________________________________________________________________________*/



//////////////////////parsig/////////////////////////////////////////////////////////////////////////////

/* int				get_Screen_Size(t_info *info); */
/* int				get_sprint(t_info *info); */

/* int					put_map_in_list(t_list **begin, int fd); */
void				print_list(t_list *begin);
int					put_map_in_tab_char(void *ptr, t_list *begin);

void				free_list(void *line);
int					free_struct(t_info *info, int code_return);
/* int					put_map_in_array(t_info *info, t_list *begin); */
int				freeAll(int codeReturn);
int				parsing(t_info *info);
void				freeContentNode(void *line);
/* int					free_texture(t_texture texture[NUM_TEXTURE]); */
//int				checkTexture(int fd, t_texture texture[NUM_TEXTURE]);
/* void				getTexture(t_texture texture[NUM_TEXTURE]); */

int		my_compare(char *s1, char *s2, size_t nbr_char);
/* int				spritevisible(t_sprite *sprite, t_player *player, float sprite_size); */
/* void			putsprite(t_sprite *sprite); */
int		skip_number(char *str);
int	skip_space(char *str);
int			get_window_size(t_list **begine);

void	print_list(t_list *tmp);
t_list	*get_node( t_list **begin, char *search, int n);
int			get_color(t_list **begin, char *name, int *num_color);
int					get_image_path(t_list **begin, char *name, int n, char **dest);
int					check_header_footer(t_list **begin);
int					put_the_same_number_of_column(t_list **begin);
int					check_file_extension(char *line, char *extension_name);
int			nb_cloumn(t_list *node);
int	isvalideCharacter(char *orientation, char character);
int	check_around_character(char **map, int y, int j);
/* int					check_character_map(t_list *begin); */
int					check_character_map(int nb_line, char *orientation);
int	isValideCharacter(char *orientation, char character);
#endif
