INC=%%%%

RM	= rm -f

INCLIB=$(INC)./minilibx-linux/lib

CC = gcc -g -Wall -Wextra -Werror -I./include/

CFLAGS= -I$(INC) -O3 -I../minilibx-linux

NAME= cub3d

SRC	=	./src/main.c\
		./src/utile/init_mlx_and_window.c\
		./src/utile/event.c\
		./src/utile/free_all.c\
		./src/parsing/main.c\
		./src/parsing/get_screen_size.c\
		./src/parsing/checkTexture.c\
		./src/parsing/get_sprint.c\
		./src/parsing/get_color.c\
		./src/parsing/put_map_in_list.c\
		./src/parsing/check_character_map.c\
		./src/parsing/get_fd.c\
		./src/parsing/put_map_in_array.c\
		./src/miniMap/miniMap.c\
		./src/playerMovement/playerMovement.c\
		./src/playerMovement/hasWallAt.c\
		./src/playerMovement/init_player.c\
		./src/cast_All_Rays/cast_All_Rays.c\
		./src/cast_All_Rays/draw_Ray.c\
		./src/cast_All_Rays/rayHorizontal.c\
		./src/cast_All_Rays/distanceBetweenPoints.c\
		./src/parsing/put_the_same_number_of_column.c\
		./src/cast_All_Rays/rayVertical.c\
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
