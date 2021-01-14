files.c = src/ft_printf.c src/tools/lst_tools.c src/tools/parser_tools.c src/parser.c  \
			src/tools/lst_add_tools.c src/tools/print_tools.c src/ft_itoa_base.c src/ft_itoa_unsigned.c src/print.c  \
			src/tools/tools.c

files.o = $(files.c:.c=.o)

ObjDir = .objects

libft_path = src/libft/

NAME = libftprintf.a

CC = 	gcc 

CFLAGS = 	-g -Wall -Wextra -Werror #-fsanitize=address


all : $(NAME)

$(NAME) : 	$(files.o) 
			@make -C $(libft_path)
			@ar -rcs $(NAME) src/libft/*.o $(files.o)
			@echo "\033[7m $(NAME) is compiled!\033[0m"
				
re		:	fclean $(NAME) 

%.o : %.c 
		@gcc $(CFLAGS)  -c  $<  -o $@
		@echo "\033[36m$<\033[0m \033[35m is compiled!\033[0m"			
			
clean :	
			@rm -rf $(files.o)
			@make -C $(libft_path) clean
			@echo "\033[7m $(NAME) clean is done!\033[0m"


fclean :	
			@rm -rf $(files.o) $(NAME)
			@make -C $(libft_path) fclean
			@echo "\033[7m $(NAME) fclean is done!\033[0m"

