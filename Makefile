INC=%%%%

RM	= rm -f

INCLIB=$(INC)./minilibx-linux/lib

CC = gcc -g -Wall -Wextra -Werror -I./include/

CFLAGS= -I$(INC) -O3 -I../minilibx-linux

NAME= cub3d

SRC	=	./src/main.c\
		./src/parsing/main.c\
		./src/parsing/get_resolution.c\
		./src/parsing/get_texture.c\
		./src/parsing/get_sprint.c\
		./src/parsing/get_color.c\
		./src/parsing/put_map_in_list.c\
		./src/parsing/check_character_map.c\
		./src/parsing/get_fd.c\
		./src/free_all.c\
		./src/parsing/put_map_in_array.c\
		./src/2DMap_PlayerMovement/event_keyboard.c\
		./src/2DMap_PlayerMovement/render_MapAndPlayer.c\
		./src/2DMap_PlayerMovement/createImage.c\
		./src/2DMap_PlayerMovement/main.c\

OBJ = $(SRC:.c=.o)

all	:$(NAME)

$(NAME)	:$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L./libft -lft -L./minilibx-linux/ -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd

clean	:
	rm -f $(NAME) $(OBJ) *~ core *.core

fclean:	clean
	$(RM) $(NAME)

re	: clean all
