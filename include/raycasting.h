#ifndef RAYCASTING_H
# define RAYCASTING_H
#include "struct.h"

int					keyPressed(int keyCode);
int					get_file_descriptor(t_info *info, char *name_file);
void				drawMap(char **map);
void				drawPlayer(t_player *player);
void				get_PositionPlayer(char **map, int *y, int *x);
int					keyRelease(int keyCode);
int					hasWallAt(float y, float x);
float				distanceBetweenPoints(float x1, float y1, float x2, float y2);
void				playerMovement(t_player *player);
void				initPlayer();
void				drawline(int corY, int corX, float distance, int color, float angle);
void				drawRect(int corX, int corY, int width, int height, int color);
int					put_the_same_number_of_column(t_list *begin);
void				cast_All_Rays(t_player *player, t_ray *ray);
void				rayHorizontal(t_ray *ray, t_player *player);
void				rayVertical(t_ray *ray, t_player *player);
void				render3d_projection(t_ray *ray, int columnId);
#endif
