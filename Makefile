INC=%%%%

RM	= rm -f

INCLIB=$(INC)./minilibx-linux/lib

CC = gcc -g -Wall -Wextra -Werror -I./include/

CFLAGS= -I$(INC) -O3 -I../minilibx-linux

NAME= cub3d

SRC	=	./src/main.c\
		./src/free_all.c\
		./src/parsing/main.c\
		./src/parsing/get_screen_size.c\
		./src/parsing/checkTexture.c\
		./src/parsing/get_sprint.c\
		./src/parsing/get_color.c\
		./src/parsing/put_map_in_list.c\
		./src/parsing/check_character_map.c\
		./src/parsing/get_fd.c\
		./src/parsing/put_map_in_array.c\
		./src/draw_Map_And_Player/drawMap.c\
		./src/draw_Map_And_Player/drawRect.c\
		./src/draw_Map_And_Player/drawPlayer.c\
		./src/playerMovement/main.c\
		./src/playerMovement/playerPosition.c\
		./src/cast_All_Rays/main.c\
		./src/cast_All_Rays/draw_Ray.c\
		./src/cast_All_Rays/rayHorizontal.c\
		./src/cast_All_Rays/distanceBetweenPoints.c\
		./src/parsing/put_the_same_number_of_column.c\
		./src/cast_All_Rays/rayVertical.c\
		./src/render_3d/main.c\
		./src/render_3d/texture.c\
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
