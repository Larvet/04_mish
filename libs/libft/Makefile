# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchene <bchene@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 13:17:45 by bchene            #+#    #+#              #
#    Updated: 2024/05/22 21:34:21 by bchene           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_LIBFT =	ft_atoi.c		ft_itoa.c \
				ft_isalnum.c	ft_isalpha.c 	ft_isascii.c	ft_isdigit.c \
				ft_isprint.c	ft_isstr.c \
				ft_memchr.c		ft_memcmp.c		ft_memcpy.c		ft_memmove.c \
				ft_memset.c		ft_bzero.c		ft_calloc.c \
				ft_strchr.c		ft_strdup.c		ft_strlcat.c 	ft_strlcpy.c \
				ft_strlen.c		ft_strncmp.c	ft_strnstr.c 	ft_strrchr.c \
				ft_tolower.c	ft_toupper.c	ft_substr.c \
				ft_strjoin.c	ft_strtrim.c	ft_strndup.c	ft_split.c \
				ft_strmapi.c	ft_striteri.c 	ft_strcpy.c \
				ft_putchar_fd.c ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c \
				ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c \
				ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c \
				ft_lstclear.c	ft_lstiter.c		ft_lstmap.c

SRCS_PRINTF	=	ft_printf.c		ft_putchars.c	ft_putbase10.c	ft_putbase16.c

SRCS_GNL =		get_next_line.c	get_next_line_utils.c

SRCS_MATH =		mt_math01.c	mt_math02.c	\
				ft_randint.c

SRCS = $(SRCS_LIBFT) $(SRCS_PRINTF) $(SRCS_GNL) $(SRCS_MATH)

OBJS = ${SRCS:.c=.o}

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

all : ${NAME}

$(NAME) : ${OBJS}
	@echo "\001\e[1;32m\002Compiling libft.a \001\e[0m\002"
	ar -rcs ${NAME} ${OBJS}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
