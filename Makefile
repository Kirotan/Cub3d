#########################################
## ARGUMENTS
#########################################
NAME	= cub3D

INCLUDES_PATH=	include
CC=				cc
CFLAGS=			-Wall -Wextra -Werror -g3
CPPFLAGS=		-lglfw

LIBS_DIR=	./libft
MLX_PATH=	./mlx/build

all: $(NAME)

########################################
## SOURCES
########################################
SRC_FILES = main.c \
			power_on.c \
			init_gamer.c \
			movement.c \
			game_loop.c \
			display_background.c \
			display_gamer.c \
			draw_shape.c \
			display_map.c \
			normalize_angle.c \
			gamer_movement.c \
			ft_free_all.c \
			cast_rays.c \
			get_intersection.c \
			pars/fill_tab.c \
			pars/init_data.c \
			pars/open_map.c \
			pars/check_filename.c \
			pars/fill_data.c \
			pars/extract_data.c \
			pars/convert_color.c \
			pars/fill_map_param.c \
			pars/parser.c \
			display_min_map.c \
			collision_management.c \
			display_image.c \
			mlx_security.c \
			inter_check_circle.c \
			pars/refill_map.c \
			texture.c \
			reverse_bytes.c \
			get_texture.c \
			proportion_calc.c \
			pars/extract_data_utils.c \
			pars/check_map.c \
			bresenham.c \
			bres_utils.c

SRC_FILES := $(addprefix src/, $(SRC_FILES))
OBJ_FILES = $(SRC_FILES:.c=.o)

########################################
## RULES
########################################

all: $(NAME)

DO_LIBS:
	@echo DOING LIBS
	@make -C $(LIBS_DIR) all

$(NAME): $(OBJ_FILES) | DO_LIBS
	@echo LINKING
	$(CC) $^ -L$(LIBS_DIR) -lft -L$(MLX_PATH) -lmlx42 -lm $(CFLAGS) $(CPPFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_FILES)
	@make -C $(LIBS_DIR) clean

fclean: clean
	@make -C $(LIBS_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re all
