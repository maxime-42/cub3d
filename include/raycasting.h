#ifndef RAYCASTING_H
# define RAYCASTING_H
#include "struct.h"

int					keyPressed(int keyCode);
int					get_file_descriptor(t_info *info, char *name_file);
void				createImage();
void				drawMap(char **map);
void				drawPlayer(t_player *player);
void				get_PositionPlayer(char **map, int *y, int *x);
int					keyRelease(int keyCode);
void				rayHorizontal();
int					hasWallAt(int y, int x);
double				normalizeAngle(double angle);
float				distanceBetweenPoints(int x1, int y1, int x2, int y2);
void				playerMovement(t_player *player);
void				createWindow(void);
void				drawRect(int line, int size, int color);
void				initPlayer();
void				ray_Facing();
void				drawline(int corY, int corX, float distance, int color, float angle);
void				Rect(int corX, int corY, int width, int height, int color);
int					put_the_same_number_of_column(t_list *begin);
void				cast_All_Rays(t_player *player, t_ray *ray);

#endif
