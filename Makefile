NAME = pipex
LIBFTPATH	= libs/srclibs/42_libft/libft.a
PRINTFPATH	= libs/srclibs/ft_printf/libftprintf.a

COMPILER 	= clang
FLAGS		= -Wall -Werror -Wextra 
LIBRARY		= $(LIBFTPATH) $(PRINTFPATH)
SOURCE		= src/main.c src/arg_handler.c src/file_handler.c src/program_handler.c

$(NAME): libs $(SOURCE)
	$(COMPILER) $(FLAGS) $(SOURCE) $(LIBRARY) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(NAME)
fclean: clean libftclean printfclean libclean
	$(info ALL CLEAN BABYYY)
re:

libs: libft printf

libft:
	$(MAKE) -C ./libs/srclibs/42_libft
printf: 
	$(MAKE) -C ./libs/srclibs/ft_printf 

libftclean:
	$(MAKE) -C ./libs/srclibs/42_libft clean
printfclean:
	$(MAKE) -C ./libs/srclibs/ft_printf clean
libclean:
	rm -f ./libs/lib*.a
