# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 14:41:19 by mel-akar          #+#    #+#              #
#    Updated: 2024/12/12 15:52:34 by ael-amma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


MLXLIB	=	MLX42/libmlx42.a

GLFWLIB	=	# gotta make some changes to build this lib as mlx ... 

CMP		=	cc

PFILES	=	ft_free.c malloc.c get_next_line.c					\
			get_next_line_utils.c ft_split.c ft_utils_I.c		\
			map_check.c ft_utils_II.c ft_utils_III.c bool_map.c	\
			ft_boolean_exp.c

RFILES	=	game.c

SRCS	=	srcs/main.c

SRCS	+=	$(addprefix srcs/parse/, $(PFILES))

SRCS	+=	$(addprefix srcs/raycast/, $(RFILES))

OBJS	=	objs/main.o

OBJS	+=	$(addprefix objs/, $(PFILES:.c=.o))

OBJS	+=	$(addprefix objs/, $(RFILES:.c=.o))

NAME	=	cub3D

CFLAGS	=	-Iincs -IMLX42/include/MLX42 -g3 #-Wall -Wextra -Werror -O3

MLXF	=	$(MLXLIB) -lglfw3 -lm -L/home/mel-akar/glfw/src/

all:		$(MLXLIB) $(NAME)

$(NAME):	$(OBJS)
	$(CMP)  $(filter-out -Iincs, $(CFLAGS)) $(OBJS)  $(MLXF) -o $@  

#should add an exporting rule for the cxx var

$(MLXLIB):
	cmake CMakeLists.txt -S MLX42/ -B MLX42/
	make -C MLX42/

objs/%.o:	srcs/raycast/%.c
	mkdir -p objs
	$(CMP) -c $(CFLAGS) $< -o $@ -MMD
	
objs/%.o:	srcs/parse/%.c
	mkdir -p objs
	$(CMP) -c $(CFLAGS) $< -o $@ -MMD
	
objs/%.o:	srcs/%.c
	mkdir -p objs
	$(CMP) -c $(CFLAGS) $< -o $@ -MMD

clean:
	rm -rf $(OBJS)
	rm -rf objs
	make clean -C MLX42 > /dev/null
	# rm -rf MLX42/cmake_install.cmake MLX42/CMakeCache.txt MLX42/Makefile MLX42/CMakeFiles

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: fclean all clean re 

-include	$(OBJS:.o=.d)
