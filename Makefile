CFLAGS =-Wall -Werror -Wextra
NAME = Cub3D

SRC_FILE = cub3d.c sprite.c
GNL_FILE = get_next_line.c get_next_line_utils.c

LIB_PATH = libft/
LIB_FILE = ft_split.c \
ft_substr.c \
ft_calloc.c \
ft_bzero.c \
ft_strjoin.c \
ft_atoi.c \
ft_putstr_fd.c \
ft_putchar_fd.c \
ft_strchr.c \
ft_sdupfr.c \
ft_isdigit.c \
ft_strlen.c

GNL_PATH = gnl/
INC= cub3d.h
SRC = ${SRC_FILE} ${addprefix ${GNL_PATH}, $(GNL_FILE)} ${addprefix ${LIB_PATH}, $(LIB_FILE)}
OBJS = ${SRC:%.c=%.o}
FRAMEWORK = -framework OpenGL -framework AppKit
LIBS = -lGLEW -lglfw -lGL
LIB = minilibx/

all: ${NAME}

$(NAME): ${INC}
	@gcc -Wall -Werror -Wextra cub3d.c sprite.c gnl/get_next_line.c gnl/get_next_line_utils.c libft/*.c -l mlx $(FRAMEWORK)

%.o : %.c
	@gcc $(FLAGS) -lXext -lX11 -L/usr/X11/lib /usr/X11/lib/libmlx.a -c -I include/ $< -o $@

clean:
	rm -f ${OBJS} ${BONUS}

fclean: clean
	rm ${NAME}

bonus :

re: clean all