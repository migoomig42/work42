# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/20 14:34:34 by jumiguel          #+#    #+#              #
#    Updated: 2015/01/20 15:26:27 by jumiguel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = ft_display.c \
	   ft_get_tab.c \
	   main.c \

OBJECTS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C libft
	@gcc -o $(NAME) $^ -L /opt/X11/lib -lmlx -lXext -lX11 -I libft/includes libft/libft.a
	@echo "executable created."

%.o: %.c
	@gcc $(CFLAGS) -o $@ -c $< -I libft/includes 
	@echo "compilation of" $< "done."

clean:
	@make clean -C libft
	@rm -f $(OBJECTS)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all re name clean fclean
