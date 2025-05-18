# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 13:23:26 by zaiicko           #+#    #+#              #
#    Updated: 2025/05/18 22:49:46 by zaiicko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
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
	MLXA = $(LINUX_MLX)/*.a
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
		args_checker.c\
		parsing/cub_map_handler.c\
		utils.c\
		parsing/parsing_utils.c\
		parsing/wall_path_handler.c\
		parsing/fc_colors_handler.c\

SRC = $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: logo $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		@mkdir -p tmp
		@touch tmp/t && chmod 777 tmp/t
		@make 2>/tmp/t -sC $(MLX) --no-print-directory
		@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXA) -o $(NAME) $(FLAGS)

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