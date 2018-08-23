#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/18 22:38:18 by jkertgat          #+#    #+#              #
#    Updated: 2018/08/08 19:49:59 by jkertgat         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS += libft/ft_lstmap.c libft/ft_striter.c libft/ft_strsplit.c libft/ft_atoi.c libft/ft_lstnew.c \
libft/ft_putendl_fd.c libft/ft_striteri.c libft/ft_bzero.c libft/ft_memalloc.c libft/ft_putnbr.c \
libft/ft_strjoin.c libft/ft_strstr.c libft/ft_isalnum.c libft/ft_memccpy.c libft/ft_putnbr_fd.c libft/ft_strlcat.c \
libft/ft_strsub.c libft/ft_isalpha.c libft/ft_memchr.c libft/ft_putstr.c libft/ft_strlen.c libft/ft_strtrim.c \
libft/ft_isascii.c libft/ft_memcmp.c libft/ft_putstr_fd.c libft/ft_strmap.c libft/ft_swap.c libft/ft_isdigit.c \
libft/ft_memcpy.c libft/ft_strcat.c libft/ft_strmapi.c libft/ft_tolower.c libft/ft_isprint.c libft/ft_memdel.c \
libft/ft_strchr.c libft/ft_strncat.c libft/ft_toupper.c libft/ft_isspace.c libft/ft_memmove.c libft/ft_strclr.c \
libft/ft_strncmp.c libft/ft_wordcnt.c libft/ft_itoa.c libft/ft_memset.c libft/ft_strcmp.c libft/ft_strncpy.c \
libft/ft_lstadd.c libft/ft_num_len.c libft/ft_strcpy.c libft/ft_strnequ.c libft/ft_lstdel.c libft/ft_putchar.c \
libft/ft_strdel.c libft/ft_strnew.c libft/ft_lstdelone.c libft/ft_putchar_fd.c libft/ft_strdup.c libft/ft_strnstr.c \
libft/ft_lstiter.c libft/ft_putendl.c libft/ft_strequ.c libft/ft_strrchr.c libft/ft_itoa_base.c libft/ft_strrev.c \
libft/ft_intlen.c  libft/ft_longint.c ft_printf.c print.c

NAME := libftprintf.a

OBJ += ft_lstmap.o ft_striter.o ft_strsplit.o ft_atoi.o ft_lstnew.o \
ft_putendl_fd.o ft_striteri.o ft_bzero.o ft_memalloc.o ft_putnbr.o \
ft_strjoin.o ft_strstr.o ft_isalnum.o ft_memccpy.o ft_putnbr_fd.o ft_strlcat.o \
ft_strsub.o ft_isalpha.o ft_memchr.o ft_putstr.o ft_strlen.o ft_strtrim.o \
ft_isascii.o ft_memcmp.o ft_putstr_fd.o ft_strmap.o ft_swap.o ft_isdigit.o \
ft_memcpy.o ft_strcat.o ft_strmapi.o ft_tolower.o ft_isprint.o ft_memdel.o \
ft_strchr.o ft_strncat.o ft_toupper.o ft_isspace.o ft_memmove.o ft_strclr.o \
ft_strncmp.o ft_wordcnt.o ft_itoa.o ft_memset.o ft_strcmp.o ft_strncpy.o \
ft_lstadd.o ft_num_len.o ft_strcpy.o ft_strnequ.o ft_lstdel.o ft_putchar.o \
ft_strdel.o ft_strnew.o ft_lstdelone.o ft_putchar_fd.o ft_strdup.o ft_strnstr.o \
ft_lstiter.o ft_putendl.o ft_strequ.o ft_strrchr.o ft_itoa_base.o ft_strrev.o \
ft_intlen.o  ft_printf.o ft_longint.o ft_printf.c print.c

.PHONY:
	clean fclean re

all: $(NAME)

$(NAME): $(SRCS)
	gcc -Wall -Wextra -Werror -I includes -c $(SRCS)
	ar rc $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
