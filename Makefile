# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 14:41:19 by mel-akar          #+#    #+#              #
#    Updated: 2024/12/25 15:01:47 by ael-amma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLXLIB	=	MLX42/libmlx42.a

CMP		=	cc

PFILES	=	ft_free.c malloc.c get_next_line.c					\
			get_next_line_utils.c ft_split.c ft_utils_I.c		\
			map_check.c ft_utils_II.c ft_utils_III.c bool_map.c	\
			ft_boolean_exp.c

RFILES	=	game.c cleaner.c utils.c render.c setup.c keyhooks.c

SRCS	=	srcs/main.c

SRCS	+=	$(addprefix srcs/parse/, $(PFILES))

SRCS	+=	$(addprefix srcs/raycast/, $(RFILES))

OBJS	=	objs/main.o

OBJS	+=	$(addprefix objs/, $(PFILES:.c=.o))

OBJS	+=	$(addprefix objs/, $(RFILES:.c=.o))

SRCS	+=	$(addprefix srcs/raycast/, $(RFILES))

OBJS	=	objs/main.o

OBJS	+=	$(addprefix objs/, $(PFILES:.c=.o))

OBJS	+=	$(addprefix objs/, $(RFILES:.c=.o))

NAME	=	cub3D

CFLAGS	=	#-Wall -Wextra #-Werror

DFLAGS	=	-Ofast #-O3 -g3 -fsanitize=address,undefined

FLAGS	=	$(CFLAGS) $(DFLAGS) -Iincs -IMLX42/include/MLX42

MLXF	=	$(MLXLIB) -ldl -lglfw -pthread -lm

all:		$(MLXLIB) $(NAME)

$(NAME):	$(OBJS)
	$(CMP) $(filter-out -Iincs, $(FLAGS)) $(OBJS) $(MLXF) -o $@

$(MLXLIB):
	cmake CMakeLists.txt -S MLX42/ -B MLX42/
	make -C MLX42/

objs/%.o:	srcs/raycast/%.c
	mkdir -p objs
	$(CMP) -c $(FLAGS) $< -o $@ -MMD
	
objs/%.o:	srcs/parse/%.c
	mkdir -p objs
	$(CMP) -c $(FLAGS) $< -o $@ -MMD
	
objs/%.o:	srcs/%.c
	mkdir -p objs
	$(CMP) -c $(FLAGS) $< -o $@ -MMD

clean:
	rm -rf $(OBJS)
	rm -rf objs
	make clean -C MLX42 > /dev/null
	rm -rf MLX42/cmake_install.cmake MLX42/CMakeCache.txt MLX42/Makefile MLX42/CMakeFiles

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: fclean all clean re 

-include	$(OBJS:.o=.d)
