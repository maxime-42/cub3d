#ifndef CUB3D_H
# define CUB3D_H
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
# define SUCCES 0
# define SUCCESS 0
# define ERROR -1
# define STDOUT 1
# define WALL '1'
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

#define TILE_SIZE 30

typedef struct		s_movePlayer
{
	int		x;
	int		y;
	int		raduis;
	int		turnDirect;
	int		walkDdirect;
	float		rotationAngle;
	float		moveSpeed;
	float		rotationSpeed;
	void		(*renderPlayer)(char **map);
}			t_movePlayer;

typedef struct		s_info
{
	char		*texture[5];
	int		window_height;
	int		window_width;
	int		nline_map;
	int		column;
	int		height;
	char		*sprint;
	void		*map;
	t_list		*begin;
	int		color_c[3];
	int		color_f[3];
	int		fd;
	void		*win_mlx;
	void		*mlx_ptr;
	t_movePlayer	*player;
}			t_info;

int			get_resolution(t_info *info);
int			get_texture(t_info *info);
int			get_sprint(t_info *info);
int			get_color(t_info *ctrl);
int			put_map_in_list(t_list **begin, int fd);
void			print_list(t_list *begin);
int			put_map_in_tab_char(void *ptr, t_list *begin);
int			check_character_map(t_list *begin);
void			free_list(void *line);
int			free_struct(t_info *info, int code_return);
int			put_map_in_array(t_info *info, t_list *begin);
int			parse_map(t_info *info);
int			draw(t_info *info);
void			my_pixel_put(t_info *info, int i, int j, int rgb);
void			renderMap(t_info *info, char **map);
int			open_window(t_info *info);
void	color_window(t_info *info);
void	print_map(char **array);
#endif
