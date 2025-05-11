# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 13:23:26 by zaiicko           #+#    #+#              #
#    Updated: 2025/05/11 13:32:59 by zaiicko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3d
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC_DIR = inc
INC = -I$(INC_DIR) -I$(LIBFT_DIR)
SRC_DIR = srcs
OBJ_DIR = obj
RM = rm -rf

SRCS =	main.c\

SRC = $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: logo $(NAME)

$(NAME):	$(OBJ) $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
		@make -C $(LIBFT_DIR) --no-print-directory

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(dir $@)
		@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) $(OBJ_DIR)
			@make clean -C $(LIBFT_DIR) --no-print-directory

fclean: clean
		@$(RM) $(NAME)
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