# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 14:41:19 by mel-akar          #+#    #+#              #
#    Updated: 2024/12/11 14:51:05 by mel-akar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLXLIB	=	MLX42/libmlx42.a
CMP		=	cc
FILES	=	main.c ft_free.c malloc.c get_next_line.c \
			get_next_line_utils.c ft_split.c ft_utils_I.c\
			map_check.c ft_utils_II.c ft_utils_III.c bool_map.c \
			ft_boolean_exp.c                                    \

SRCS	=	$(addprefix srcs/, $(FILES))
OBJS	=	$(addprefix objs/, $(FILES:.c=.o))
NAME	=	cub3D
CFLAGS	=	-g3 -fsanitize=address,undefined -Iincs -IMLX42/include/MLX42 -Wall -Wextra -Werror -O3
MLXF	=	-framework Cocoa -framework OpenGL -framework IOKit -lglfw -L/Users/$(shell whoami)/.brew/opt/glfw/lib

all:		$(MLXLIB) $(NAME)

$(NAME):	$(OBJS)
	$(CMP) $(filter-out -Iincs, $(CFLAGS)) $(MLXLIB) $(MLXF) $(OBJS) -o $@

$(MLXLIB):
	make -C MLX42/

objs/%.o:	srcs/%.c
	mkdir -p objs
	$(CMP) -c $(CFLAGS) $< -o $@ -MMD

clean:
	rm -rf $(OBJS)
	rm -rf objs
	make clean -C MLX42/

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: fclean all clean re 

-include	$(OBJS:.o=.d)
