OS		=	$(shell uname)
			ifeq ($(OS), Darwin)
				MLXLIB	=	blanmac
			else
				MLXLIB	=	blanlinux
			endif
CMP		=	cc
FILES	=	main.c ft_free.c malloc.c get_next_line.c \
			get_next_line_utils.c ft_split.c ft_utils_I.c\
			map_check.c ft_utils_II.c ft_utils_III.c bool_map.c \
			ft_boolean_exp.c                                    \

SRCS	=	$(addprefix srcs/, $(FILES))
OBJS	=	$(addprefix objs/, $(FILES:.c=.o))
NAME	=	cub3D
CFLAGS	=	-g3 -fsanitize=address,undefined -Iincs -Wall -Wextra -Werror -O3


all:		$(NAME)

$(NAME):	$(OBJS)
	$(CMP) $(filter-out -Iincs, $(CFLAGS)) $(OBJS) -o $@

objs/%.o:	srcs/%.c
	mkdir -p objs
	$(CMP) -c $(CFLAGS) $< -o $@ -MMD

clean:
	rm -rf $(OBJS)
	rm -rf objs

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: fclean all clean re 

-include	$(OBJS:.o=.d)