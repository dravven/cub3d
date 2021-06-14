NAME = cub3D


SRCS =		main.c \
		get_next_line.c \
		get_next_line_utils.c \
		calc_2.c \
		key_2.c \
		load_texture.c \
		key.c \
		error.c \
		calc.c \
		screenshot.c \
		parser_error_map.c \
		parser_texture.c \
		parser_res.c \
		make_map.c \
		map_size_and_write.c \
		calc_wall.c \
		sprite_malloc.c \
		sort_sprites.c\
		parser_color.c \
		ft_isdigit.c \
		ft_strlen.c \
		ft_lstadd_back.c \
		ft_calloc.c \
		ft_bzero.c \
		ft_strdup.c \
		ft_atoi.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_lstlast.c
		
IBNAME = cub3d.a

FLAGS = -Wall -Wextra -Werror -MMD

MLXLIB = minilibx_mms_20200219

MLX = libmlx.dylib


DEP = $(SRCS:.c=.d)

MLXFLAGS = -framework OpenGL -framework AppKit

OBJECTS = $(patsubst %.c,%.o,$(SRCS))

all: $(NAME)

-include $(DEP)

$(NAME): $(OBJECTS)
	make -C $(MLXLIB)
	mv minilibx_mms_20200219/$(MLX) ./
	gcc -L. -lmlx $(MLXFLAGS) $(OBJECTS) -o $(NAME)

%.o:%.c
	gcc $(FLAGS) -I cub.h -I $(MLXLIB) -c $< -o $@

norme:
	@norminette  $(SRCS) cube.h

clean:
	rm -f $(OBJECTS)
	rm -f $(MLX)
	rm -f $(DEP)

fclean: clean
	rm -rf $(NAME)
	/bin/rm -f $(LIBNAME)
	/bin/rm -f screenshot.bmp

re: fclean all

