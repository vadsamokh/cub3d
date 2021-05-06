.PHONY:	re all clean fclen

NAME =	cub3D

SRCS =	./main.c \
		./errors.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \
		./parser/parser.c \
		./parser/params_fill_1.c \
		./parser/params_fill_2.c \
		./parser/parse_map.c \
		./parser/check_map.c \
		./parser/player_init.c \
		./cub/mlx.c \
		./cub/hooks.c \
		./cub/cast_rays.c \
		./cub/draw_world1.c \
		./cub/draw_world2.c \
		./cub/draw_sprites.c \
		./cub/sprites_utils.c \
		./cub/screenshot.c

OBJS =	./main.o \
		./errors.o \
		./get_next_line.o \
		./get_next_line_utils.o \
		./parser.o \
		./params_fill_1.o \
		./params_fill_2.o \
		./parse_map.o \
		./check_map.o \
		./player_init.o \
		./mlx.o \
		./hooks.o \
		./cast_rays.o \
		./draw_world1.o \
		./draw_world2.o \
		./draw_sprites.o \
		./sprites_utils.o \
		./screenshot.o

all:	${NAME}

${NAME}:
		make -C ./libft/
		cp ./libft/libft.a .
		make -C ./minilibx_mms_20200219/
		cp ./minilibx_mms_20200219/libmlx.dylib .
		gcc ${SRCS} -o ${NAME} -L. -I. libft.a libmlx.dylib -framework OpenGL -framework Appkit -O2

clean:
		$(MAKE) clean -C ./libft/
		$(MAKE) clean -C ./minilibx_mms_20200219/
		rm -f ${OBJS}

fclean:	clean
		rm -f libft.a
		rm -f libmlx.dylib
		rm -f ${NAME}

re:		fclean all
