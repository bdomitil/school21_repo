# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 09:40:08 by bdomitil          #+#    #+#              #
#    Updated: 2020/11/06 18:12:41 by bdomitil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

files.c =  $(wildcard ./*.c)

files.o = $(files.c:.c=.o)

NAME = libft.a


all :	libft.a
		
$(NAME) : $(files.o)
		ar -rcs libft.a $(files.o)

%.o : %.c 
		gcc -Wall -Wextra -Werror -c  $<  -o $@ 

clean :  
		rm -f *.o

fclean :	clean
		rm  -f $(NAME)

re	:  fclean libft.a	


.PHONY : all clean $(NAME) fclean
