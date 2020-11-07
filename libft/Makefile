# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdomitil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 09:40:08 by bdomitil          #+#    #+#              #
#    Updated: 2020/11/07 23:57:23 by bdomitil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

files.c = ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_memccpy.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c  ft_islower.c  \
                    libft.h ft_char_index.c ft_isupper.c ft_space.c ft_strcmp.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c	ft_lstadd_back.c

bonus.o = $(BONUS:.c=.o)

files.o = $(files.c:.c=.o)

NAME = libft.a


all :	libft.a
		
$(NAME) : $(files.o)
		ar -rcs libft.a $(files.o)

bonus :  $(files.o) $(bonus.o)
		ar -rcs $(NAME) $(files.o) $(bonus.o) 

%.o : %.c 
		gcc -Wall -Wextra -Werror -c  $<  -o $@ 

clean :  
		rm -f *.o

fclean :	clean
		rm  -f $(NAME)

re	:  fclean libft.a	


.PHONY : all clean  fclean bonus
