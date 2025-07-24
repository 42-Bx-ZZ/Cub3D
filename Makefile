# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 13:23:26 by zaiicko           #+#    #+#              #
#    Updated: 2025/07/24 12:10:41 by lowatell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D
CC = cc
CFLAGS = -Wall -Werror -Wextra -O3
MATH_FLAG = -lm
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC_DIR = inc
INC = -I$(INC_DIR) -I$(LIBFT_DIR)
SRC_DIR = srcs
OBJ_DIR = obj
RM = rm -rf

LINUX_MLX = minilibx-linux
LINUX_FLAGS = -lmlx -lXext -lX11 -L $(LINUX_MLX)

MAC_MLX = minilibx_opengl_20191021
MAC_FLAGS = -lmlx -framework OpenGL -framework AppKit -L $(MAC_MLX)

ifeq ($(shell uname -s), Linux)
	MLX = $(LINUX_MLX)
	MLXA = $(LINUX_MLX)/libmlx.a $(LINUX_MLX)/libmlx_Linux.a
	FLAGS = $(LINUX_FLAGS)
else ifeq ($(shell uname -s), Darwin)
	MLX = $(MAC_MLX)
	MLXA = $(MAC_MLX)/*.a
	FLAGS = $(MAC_FLAGS)
else
	MLXA = 
	FLAGS = 
endif

SRCS =	main.c\
		parsing/cub_file_handler.c\
		utils.c\
		parsing/path_handler.c\
		parsing/fc_colors_handler.c\
		parsing/map_handler.c\
		parsing/map_handler_utils.c\
		parsing/cub_file_handler_utils.c\
		parsing/map_handler_utils2.c\
		engine/setup_mlx.c\
		engine/setup_mlx_utils.c\
		moves/moves.c\
		engine/get_map.c\
		engine/load_sprites.c\
		engine/keys.c\
		graphics/graphic_parsing.c\
		graphics/view.c\
		graphics/raycasting.c\
		graphics/crosshair.c\
		graphics/crosshair_utils.c\
		graphics/raycasting_utils.c\
		moves/hitbox.c\
		graphics/dda.c\
		graphics/dda_utils.c\
		engine/door_check.c\
		graphics/print_infos.c\
		graphics/ennemy_draw.c\
		engine/ennemy_moves.c\
		graphics/colors.c\
		engine/hp_manager.c\
		graphics/draw_map.c\
		graphics/draw_items.c\
		engine/ennemies.c\
		engine/gun_animation.c\
		graphics/loading_screen.c\
		graphics/loading_screen_utils.c\
		graphics/loading_screen_utils2.c\
		graphics/health_bar.c\
		engine/backtracking_z.c\
		engine/boss.c\
		clean_utils.c\
		clean_utils2.c\
		is_valid_map_char.c\

SRC = $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: logo $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		@mkdir -p tmp
		@touch tmp/t && chmod 777 tmp/t
		@make 2>/tmp/t -sC $(MLX) --no-print-directory
		@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXA) -o $(NAME) $(FLAGS) $(MATH_FLAG)

$(LIBFT):
		@make -C $(LIBFT_DIR) --no-print-directory

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(dir $@)
		@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

clean:
		@$(RM) $(OBJ_DIR)
		@make clean -sC $(MLX) --no-print-directory
		@make clean -C $(LIBFT_DIR) --no-print-directory

fclean: clean
		@$(RM) $(NAME)
		@$(RM) tmp
		@make fclean -C $(LIBFT_DIR) --no-print-directory

re:		fclean all

logo:
	@echo "\033[31m"
	@echo "                                                                         "
	@echo "   _|_|_|            _|        _|_|_|          _|  "
	@sleep 0.01
	@echo " _|        _|    _|  _|_|_|          _|    _|_|_|  "
	@sleep 0.01
	@echo " _|        _|    _|  _|    _|    _|_|    _|    _|  "
	@sleep 0.01
	@echo " _|        _|    _|  _|    _|        _|  _|    _|  "
	@sleep 0.01
	@echo "   _|_|_|    _|_|_|  _|_|_|    _|_|_|      _|_|_|  "
	@sleep 0.01
	@echo "                                                   "
	@sleep 0.01
	@echo "                                                   "

.PHONY:	fclean re all clean logo