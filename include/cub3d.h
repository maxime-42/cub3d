#ifndef CUB3D_H
# define CUB3D_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include "struct.h"

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

# define STDOUT 1
# define WALL '1'

# define FOV_ANGLE  60 * (M_PI / 180)
# define WALL_STRIP_WIDTH  1
# define NUM_RAYS g_window_width / WALL_STRIP_WIDTH


/*variable globals*/
t_info				*g_info;
t_player			g_player;
void				*g_mlx_ptr;
void				*g_img_ptr;
void				*g_win_mlx;
int					*g_image_data;
int					g_width;//largeur de la fenetre
int					g_height;//hauteur de la fenetre
int					g_window_width;//initialiser dans les le fichier initPlayer
int					g_window_height;//initialiser dans les le fichier initPlayer
char				**g_map;
t_ray				g_ray;

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
int					parsing_map(t_info *info);
int					draw(t_info *info);
int					keyPressed(int keyCode);
int					get_file_descriptor(t_info *info, char *name_file);
void				createImage();
int					freeAll(int codeReturn);
void				drawMap(char **map);
void				drawPlayer();
void				get_PositionPlayer(char **map, int *y, int *x);
int					keyRelease(int keyCode);
void				print_map(char **array);
void				rayHorizontal();
void				cast_All_Rays();
int					hasWallAt(int y, int x);
double				normalizeAngle(double angle);
float				distanceBetweenPoints(int x1, int y1, int x2, int y2);
void				dda_algorithm();
void				playerMovement(void);
void				createWindow(void);
void				drawSquare(int line, int size, int color);
void				initPlayer();
void				freeContentNode(void *line);
void				draw_Ray(double angle, float lenght);
void				ray_Facing();
#endif
