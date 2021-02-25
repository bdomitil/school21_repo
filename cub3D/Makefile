# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/22 19:13:25 by bdomitil          #+#    #+#              #
#    Updated: 2021/02/25 16:59:48 by bdomitil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

files.c = src/cub_utils1.c src/config_parser.c src/parse_utils.c

#CFLAGS = -g -Wall -Wextra -Werror					
CFLAGS = -g 
files.o = $(files.c:.c=.o)

NAME = cub3D


all :	$(NAME)

$(NAME) : $(files.o)
		@make -C libft/ 
		@ar -rcs cub_lib.a $(files.o)
		@echo "\033[7m cub_lib is compiled!\033[0m"
		@gcc $(CFLAGS) src/cub.c libft/libft.a cub_lib.a -o cub3D
		@echo "\033[7m CUB PROGRAM IS READY TO BE USED!\033[0m"


%.o : %.c 
		@gcc $(CFLAGS) -c  $<  -o $@
		@echo "\033[36m$<\033[0m \033[35m is compiled!\033[0m"

clean :  
		@rm -f $(files.o)
		@make -C libft/ clean
		@echo "\033[7mclean is done!\033[0m"

fclean : clean
		@rm  -f $(NAME)
		@make -C libft/ fclean
		@echo "\033[7mfclean is done!\033[0m"

re	:  fclean $(NAME)	


.PHONY : all clean  fclean 
