#**************************************************************************** #
#                                                                             #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 15:21:27 by jumiguel          #+#    #+#              #
#    Updated: 2014/11/06 15:33:05 by jumiguel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJECT = ft_isdigit.o \
		 ft_isalnum.o \
		 ft_memcpy.o \
		 ft_strsplit.o \
		 ft_putchar.o \
		 ft_strlcat.o \
		 ft_strncmp.o \
		 ft_tolower.o \
		 ft_atoi.o \
		 ft_isalpha.o \
		 ft_isprint.o \
		 ft_putstr.o \
		 ft_strcpy.o \
		 ft_strlen.o \
		 ft_strncpy.o \
		 ft_toupper.o \
		 ft_bzero.o \
		 ft_isascii.o \
		 ft_memccpy.o \
		 ft_memset.o \
		 ft_strcat.o \
		 ft_strdup.o \
		 ft_strncat.o \
		 ft_strstr.o \
		 ft_strnstr.o \
		 ft_memmove.o \
		 ft_strchr.o \
		 ft_strrchr.o \
		 ft_memchr.o \
		 ft_memcmp.o \
		 ft_strcmp.o \
		 ft_memalloc.o \
		 ft_memdel.o \
		 ft_striter.o \
		 ft_striteri.o \
		 ft_strmap.o \
		 ft_swap.o \
		 ft_strmapi.o \
		 ft_strnew.o \
		 ft_strclr.o \
		 ft_strdel.o \
		 ft_strequ.o \
		 ft_strnequ.o \
		 ft_strsub.o \
		 ft_strjoin.o \
		 ft_strtrim.o \
		 ft_putendl.o \
		 ft_putnbr.o \
		 ft_putchar_fd.o \
		 ft_putstr_fd.o \
		 ft_putendl_fd.o \
		 ft_putnbr_fd.o \
		 get_next_line.o \

INCLUDE = -I. -I./includes  

CC = gcc 

CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(INCLUDE) -c  $(OBJECT:.o=.c)
	@ar rc $(NAME) $(OBJECT)

clean:
	rm -f $(OBJECT)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all re name cleam fclean 

