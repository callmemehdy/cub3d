FILES	=	main.c ft_free.c malloc.c get_next_line.c \
			get_next_line_utils.c ft_split.c ft_utils.c\

SRCS	=	$(addprefix srcs/, $(FILES))
OBJS	=	$(addprefix objs/, $(FILES:.c=.o))
NAME	=	cub3D
CFLAGS	=	-Iincs -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
	cc $(filter-out -Iincs, $(CFLAGS)) $(OBJS) -o $@

objs/%.o:	srcs/%.c
	mkdir -p objs
	cc -c $(CFLAGS) $< -o $@ -MMD

clean:
	rm -rf $(OBJS)
	rm -rf objs

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: fclean all clean re 

-include	$(OBJS:.o=.d)