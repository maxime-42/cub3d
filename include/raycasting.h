#ifndef RAYCASTING_H
# define RAYCASTING_H
#include "cub3d.h"

int				keyPressed(int keyCode);
int				get_file_descriptor(t_info *info, char *name_file);
void				get_PositionPlayer(char **map, int *y, int *x);
int				keyRelease(int keyCode);
int				hasWallAt(float y, float x);
float				distanceBetweenPoints(float x1, float y1, float x2, float y2);
void				playerMovement(t_player *player);
void				initPlayer(t_player *player);;
void				drawline(int corY, int corX, float distance, int color, float angle);
void				drawRect(int corX, int corY, int width, int height, int color);
int				put_the_same_number_of_column(t_list *begin);
void				cast_All_Rays(t_player *player, t_ray *ray);
void				rayHorizontal(t_ray *ray, t_player *player);
void				rayVertical(t_ray *ray, t_player *player);
void				render3d_projection(t_ray *ray, int columnId);
void				put_sprite(t_ray *ray, int top, int wallStripHeight, int wallBottom, int columnId);
void				draw_Wall(t_ray *ray, t_wall *wall, int columnId);
void				playerPosition(t_player *player);
float				normalizeAngle(float angle);
void				bmp_exporter(char *fileName);
void				miniMap(t_player *player, char **map);

#endif
