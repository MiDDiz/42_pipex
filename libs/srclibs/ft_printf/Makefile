# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 11:02:32 by jnaftana          #+#    #+#              #
#    Updated: 2022/01/21 11:02:32 by jnaftana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
PRINTDIR = src
LIBDIR = libft

SRCS = $(PRINTDIR)/ft_printf.c \
		$(PRINTDIR)/helper_types.c \
		$(PRINTDIR)/helper_types_2.c \
		$(LIBDIR)/ft_putchar_fd.c \
		$(LIBDIR)/ft_putstr_fd.c \
		$(LIBDIR)/ft_strlen.c \
		$(LIBDIR)/ft_itoa.c \
		$(LIBDIR)/ft_calloc.c \
		$(LIBDIR)/ft_strlcat.c \
		$(LIBDIR)/ft_bzero.c \
		$(LIBDIR)/ft_strlcpy.c \
		$(LIBDIR)/ft_utoa.c \
		$(LIBDIR)/ft_strupper.c \
		$(LIBDIR)/ft_toupper.c \
		$(LIBDIR)/ft_hextoa.c

OBJS =	$(SRCS:.c=.o)
CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

$(NAME):	$(OBJS)
	ar -rcv $@ $^

clean:
	rm -f ${OBJS} libftprintf.a

fclean:	clean
	rm -f ${NAME}

re:	fclean all