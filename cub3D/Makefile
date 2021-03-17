# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/22 19:13:25 by bdomitil          #+#    #+#              #
#    Updated: 2021/03/17 20:28:20 by bdomitil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

files.c = src/cub_utils1.c src/config_parser.c src/parse_utils.c src/parse_utils2.c  \
src/flood_fill.c src/test_utils.c src/parse_utils3.c src/cub.c src/ft_mlx_start.c  \
src/casting_utils.c src/draw.c src/draw_text_walls.c 

#CFLAGS = -g -Wall -Wextra -Werror					
CFLAGS = -g
#MlxFlags = -Lmlx/ -lmlx -framework OpenGL -framework AppKit 
files.o = $(files.c:.c=.o)

NAME = cub3D


all :	$(NAME)

$(NAME) : $(files.o)
		@make -C libft/
		@make -C mlx/
		@gcc $(CFLAGS) $(MlxFlags) $(files.c) libft/libft.a libmlx.a -o cub3D
		@echo "\033[7m CUB PROGRAM IS READY TO BE USED!\033[0m"


%.o : %.c 
		@gcc $(CFLAGS) -Imlx/ -c  $<  -o $@
		@echo "\033[36m$<\033[0m \033[35m is compiled!\033[0m"

clean :  
		@rm -f $(files.o)
		@make -C libft/ clean
		@make -C mlx/ clean
		@echo "\033[7mclean is done!\033[0m"

fclean : clean
		@rm  -f $(NAME)
		@make -C libft/ fclean
		@echo "\033[7mfclean is done!\033[0m"

re	:  fclean $(NAME)	


.PHONY : all clean  fclean 
