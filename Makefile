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
		./src/free_all.c\
		./src/parsing/put_map_in_array.c\
		./src/raycastng/main.c\
		./src/raycastng/my_put_pixel.c\
		./src/raycastng/open_window.c\
		./src/raycastng/render.c\

OBJ = $(SRC:.c=.o)

all	:$(NAME)

$(NAME)	:$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L./libft -lft -L./minilibx-linux/ -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd

clean	:
	rm -f $(NAME) $(OBJ) *~ core *.core

fclean:	clean
	$(RM) $(NAME)

re	: clean all

# CC	= gcc

# LIBFT	= ./libft

# HEADERS	= -./include/

# CFLAGS	= -g -Wall -Wextra -Werror

# RM	= rm -f

# NAME	= cub3d

# SRC	=	./src/main.c\
# 		./src/parsing/main.c\
# 		./src/parsing/get_resolution.c\
# 		./src/parsing/get_texture.c\
# 		./src/parsing/get_sprint.c\
# 		./src/parsing/get_color.c\
# 		./src/parsing/put_map_in_list.c\
# 		./src/parsing/check_character_map.c\
# 		./src/free_all.c\
# 		./src/parsing/put_map_in_array.c\
# 		./src/raycastng/main.c\

# OBJ	= $(SRC:.c=.o)

# all:	$(NAME)

# $(NAME):$(OBJ)
# 	make bonus -C $(LIBFT)
# 	$(CC) $(CFLAGS)  -o $(NAME)  $(SRC) -L./libft -lft -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd

# 	# $(CC) $(CFLAGS)  -o $(NAME)  $(SRC) -L./libft -lft -L./minilibx-linux -lmlx -L$(INCLIB) -lXext -lX11 -lm

# 	# cp ./libft/libft.a ./
# # $(CC) $(CFLAGS)  -o $(NAME)  $(SRC) libft.a -L./minilibx-linux -lmlx -L$(INCLIB) -lXext -lX11 -lm

# clean:
# 	$(RM) $(OBJ)

# fclean:	clean
# 	$(RM) $(NAME)

# re:	fclean all
