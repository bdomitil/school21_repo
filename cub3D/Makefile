# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/22 19:13:25 by bdomitil          #+#    #+#              #
#    Updated: 2021/04/24 16:03:08 by bdomitil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

files.c = src/cub_utils1.c src/config_parser.c src/parse_utils.c src/parse_utils2.c  \
src/flood_fill.c src/parse_utils3.c src/cub.c src/ft_mlx_start.c  \
src/casting_utils.c src/draw.c src/draw_text_walls.c src/drawing_utils.c src/moving_utils.c  \
src/key_utils.c src/sprite_draw.c src/screen_save.c src/events.c

CFLAGS = -g -Wall -Wextra -Werror
# CFLAGS = -g
# MlxFlags = -Lmlx/ -lmlx -framework OpenGL -framework AppKit 
MlxFlags = -framework OpenGL -framework AppKit
files.o = $(files.c:.c=.o)

NAME = cub3D


all :	lib_compil mlx_compil $(NAME) 

$(NAME) : $(files.o) include/cub_header.h
		gcc $(CFLAGS) $(MlxFlags) $(files.o) libft/libft.a minilibx/libmlx.a -o cub3D
		@echo "\033[7m CUB PROGRAM IS READY TO BE USED!\033[0m"


lib_compil:
		@make -C libft/

mlx_compil: 
		@make -C minilibx/

%.o : %.c 
		@gcc $(CFLAGS)  -c  $<  -o $@
		@echo "\033[36m$<\033[0m \033[35m is compiled!\033[0m"

clean :  
		@rm -f $(files.o)
		@make -C libft/ clean
		@make -C minilibx/ clean
		@echo "\033[7mclean is done!\033[0m"

fclean : clean
		@rm  -f $(NAME)
		@make -C libft/ fclean
		@echo "\033[7mfclean is done!\033[0m"

re	:  fclean all	


.PHONY : all clean  fclean 
