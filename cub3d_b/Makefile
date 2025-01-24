# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 14:41:19 by mel-akar          #+#    #+#              #
#    Updated: 2025/01/24 17:15:06 by mel-akar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLXLIB	=	MLX42/libmlx42.a

CMP		=	cc

PFILES	=	ft_free_bonus.c malloc_bonus.c get_next_line_bonus.c			\
			get_next_line_utils_bonus.c ft_split_bonus.c ft_utils_I_bonus.c		\
			map_check_bonus.c ft_utils_II_bonus.c ft_utils_III_bonus.c bool_map_bonus.c	\
			ft_boolean_exp_bonus.c ft_utils_IV_bonus.c

RFILES	=	cleaner_bonus.c draw_bonus.c game_bonus.c hooks_bonus.c raycast_bonus.c render_utils_bonus.c \
			render_bonus.c setup_bonus.c update_bonus.c utils_bonus.c animation_bonus.c render_tools_bonus.c \
			

SRCS	=	srcs/main_bonus.c

SRCS	+=	$(addprefix srcs/parse/, $(PFILES))

SRCS	+=	$(addprefix srcs/raycast/, $(RFILES))

OBJS	+=	$(addprefix objs/, $(PFILES:.c=.o))

OBJS	+=	$(addprefix objs/, $(RFILES:.c=.o))

SRCS	+=	$(addprefix srcs/raycast/, $(RFILES))

OBJS	+=	objs/main_bonus.o

NAME	=	cub3D_bonus

CFLAGS	=	#-Wall -Wextra #-Werror

DFLAGS	=	#-Ofast -O3 -g3 -fsanitize=address,undefined

FLAGS	=	$(CFLAGS) $(DFLAGS) -Iincs -IMLX42/include/MLX42

MLXF	=	$(MLXLIB) -ldl -lglfw -pthread -lm

all:		$(MLXLIB) $(NAME)

$(NAME):	$(OBJS)
	$(CMP) $(filter-out -Iincs, $(FLAGS)) $(OBJS) $(MLXF) -o $@

$(MLXLIB):
	cmake CMakeLists.txt -S MLX42/ -B MLX42/
	make -C MLX42/

objs/%_bonus.o:	srcs/raycast/%_bonus.c
	mkdir -p objs
	$(CMP) -c $(FLAGS) $< -o $@ -MMD
	
objs/%_bonus.o:	srcs/parse/%_bonus.c
	mkdir -p objs
	$(CMP) -c $(FLAGS) $< -o $@ -MMD
	
objs/%_bonus.o:	srcs/%_bonus.c
	mkdir -p objs
	$(CMP) -c $(FLAGS) $< -o $@ -MMD

clean:
	rm -rf $(OBJS)
	rm -rf objs
	@if [ -f MLX42/Makefile ]; then\
		make clean -C MLX42 > /dev/null;\
	fi 
	rm -rf MLX42/cmake_install.cmake \
	MLX42/CMakeCache.txt \
	MLX42/Makefile \
	MLX42/CMakeFiles \

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: fclean all clean re 

-include	$(OBJS:.o=.d)
