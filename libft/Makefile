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

SRCS = ft_isdigit.c \
		 ft_isalnum.c \
		 ft_memcpy.c \
		 ft_strsplit.c \
		 ft_putchar.c \
		 ft_strlcat.c \
		 ft_strncmp.c \
		 ft_tolower.c \
		 ft_atoi.c \
		 ft_isalpha.c \
		 ft_isprint.c \
		 ft_putstr.c \
		 ft_strcpy.c \
		 ft_strlen.c \
		 ft_strncpy.c \
		 ft_toupper.c \
		 ft_bzero.c \
		 ft_isascii.c \
		 ft_memccpy.c \
		 ft_memset.c \
		 ft_strcat.c \
		 ft_strdup.c \
		 ft_strncat.c \
		 ft_strstr.c \
		 ft_strnstr.c \
		 ft_memmove.c \
		 ft_strchr.c \
		 ft_strrchr.c \
		 ft_memchr.c \
		 ft_memcmp.c \
		 ft_strcmp.c \
		 ft_memalloc.c \
		 ft_memdel.c \
		 ft_striter.c \
		 ft_striteri.c \
		 ft_strmap.c \
		 ft_swap.c \
		 ft_strmapi.c \
		 ft_strnew.c \
		 ft_strclr.c \
		 ft_strdel.c \
		 ft_strequ.c \
		 ft_strnequ.c \
		 ft_strsub.c \
		 ft_strjoin.c \
		 ft_strtrim.c \
		 ft_putendl.c \
		 ft_putnbr.c \
		 ft_putchar_fd.c \
		 ft_putstr_fd.c \
		 ft_putendl_fd.c \
		 ft_putnbr_fd.c \
		 get_next_line.c \

OBJECTS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

%.o: %.c
	@gcc $(CFLAGS) -o $@ -c $< -I includes
	@echo "compilation of" $< "done."	

clean:
	rm -f $(OBJECTS)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all re name clean fclean 

