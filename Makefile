
INC=%%%%

RM	= rm -f

INCLIB=$(INC)./minilibx-linux/lib

CC = gcc -g -Wall -Wextra -Werror -I./include/

CFLAGS= -I$(INC) -O3 -I../minilibx-linux

NAME= cub3D

SRC	=	./src/main.c\
		./src/utile/event.c\
		./src/utile/init_global_variable.c\
		./src/utile/mini_map.c\
		./src/utile/load_ptr_textures_in_array.c\
		./src/utile/normalize_angle.c\
		./src/utile/check_argument.c\
		./src/utile/free_all.c\
		./src/parsing/parsing.c\
		./src/parsing/utile.c\
		./src/parsing/get_window_size.c\
		./src/parsing/get_image_path.c\
		./src/parsing/get_color.c\
		./src/parsing/check_character_map_utile.c\
		./src/parsing/check_character_map.c\
		./src/parsing/get_fd.c\
		./src/parsing/check_header_footer_map.c\
		./src/playerMovement/player_movement.c\
		./src/playerMovement/has_wall_at.c\
		./src/playerMovement/init_player.c\
		./src/cast_All_Rays/cast_all_rays.c\
		./src/cast_All_Rays/ray_horizontal.c\
		./src/cast_All_Rays/distance_between_points.c\
		./src/cast_All_Rays/ray_vertical.c\
		./src/render_3d/render_3d_projection.c\
		./src/screenshot/bmp_exporter.c\
		./src/sprite/init_sprite.c\
		./src/sprite/init_sprite_utile.c\
		./src/sprite/sprite_utile.c\
		./src/sprite/sprite.c\


OBJ = $(SRC:.c=.o)

all	:$(NAME)

$(NAME)	:$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L./libft -lft -L./minilibx-linux/ -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd

clean	:
	rm -f $(NAME) $(OBJ) *~ core *.core

fclean:	clean
	$(RM) $(NAME)

re	: clean all
